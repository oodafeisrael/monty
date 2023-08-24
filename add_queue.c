#include "monty.h"

/**
* add_queue - Adds a new node to the end or tail of the stack
* @head: Pointer to the head of the stack
* @n: New value to be added to the stack
* Return: no return value
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_value;
	stack_t *current = *head;

	new_value = malloc(sizeof(stack_t));
	if (new_value == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new_value->n = n;
	new_value->next = NULL;
	if (*head == NULL)
	{
		new_value->prev = NULL;
		*head = new_value;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_value;
	new_value->prev = current;
}
