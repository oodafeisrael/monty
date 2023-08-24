#include "monty.h"

/**
* i_push - puses element into the stack
* @head: pointer to the head of the stack
* @line_num: line number
* Return: return nothing
*/
void i_push(stack_t **head, unsigned int line_num)
{
	int n;

	if (!cont.arg || (!isdigit(*cont.arg) && *cont.arg != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(cont.file);
		free(cont.temp_buff);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(cont.arg);
	if (cont.is_stack == 0)
		add_stack(head, n);
	else
		add_queue(head, n);
}
/**
* p_pall - prints all values in a stack
* @head: pointer to the head of the stack
* @line_num: line number
* Return: nothing
*/
void p_pall(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;
	unsigned int index = 0;

	while (current)
	{
		printf("Value at index %u (L%d): %d\n", index, 
				line_num, current->n);
		current = current->next;
		index++;
	}
}
