#include "monty.h"
/**
* m_stack - prints top value of stack
* @head: stack head
* @line_num: line number
* Return: nothing
*/
void m_stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	cont.is_stack = 0;
}

/**
* add_stack - adds a new node to the head of the stack
* @head: Pointer to the head of the stack
* @n: New value to be added to the stack
* Return: No return value
*/
void add_stack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
