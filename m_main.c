#include "monty.h"
cont_t cont = {NULL, NULL, NULL, 0};
/**
* main - Monty code interpretation
* @argc:command line argument count
* @argv: argument vectors
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *temp_buff;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *head = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		temp_buff = NULL;
		read_line = getline(&temp_buff, &size, file);
		if (read_line > 0)
		{
			cont.temp_buff = temp_buff;
			line_num++;
			execute(temp_buff, &head, line_num, file);
		}
	}
	free(temp_buff);
	free_stack(head);
	fclose(file);
	return (0);
}
