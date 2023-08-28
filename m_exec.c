#include "monty.h"

/**
* execute - Executes opcodes from a line of bytecode
* @line_num: line number
* @file: pointer to the stack
* @temp_buff: line content from bytecode file
* @head: pointer to the stack
* Return: 0 on success, otherwise 1
*/
int execute(char *temp_buff, stack_t **head, unsigned int line_num, FILE
		*file)
{
	char *opcode;
	/*char *arg;*/
	int x;

	instruction_t opst[] = {
		{"push", i_push},
		{"pall", p_pall},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};

	opcode = strtok(temp_buff, " \n\t");
	if (!opcode || opcode[0] == '0')
		return (0);
	cont.arg = strtok(NULL, " \n\t");
	for (x = 0; opst[x].opcode; x++)
	{
		if (strcmp(opcode, opst[x].opcode) == 0)
		{
			opst[x].f(head, line_num);
			return (1);
		}
	}
	fprintf(stderr, "L%d:Unknown instruction %s\n", line_num, opcode);
	fclose(file);
	free_stack(*head);
	exit(EXIT_FAILURE);
	return (0);
}
