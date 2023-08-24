#include "monty.h"

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
