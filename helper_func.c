#include "monty.h"

/**
 * stack_length - returns length of stack
 * @head: pointer to head of stack
 * Return: length of stack
 */
size_t stack_length(stack_t **head)
{
	stack_t *node;
	unsigned int i;

	node = *head;
	for (i = 0; node != NULL; i++)
	{
		node = node->next;
	}

	return (i);
}
