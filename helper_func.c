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

/**
* rotl - Rotates the stack to the top.
* @head: Pointer to stack.
* @line_num: Number line of the command rotl in the monty file
*/

void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	if (head != NULL && (*head) != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		(*head) = (*head)->next;
		tmp->next = (*head)->prev;
		(*head)->prev = NULL;
		tmp->next->next  = NULL;
		tmp->next->prev = tmp;
	}
}

/**
* rotr - rotates stack to the bottom
* @head: Pointer to a pointer that points to the stack
* @line_num: Number line of the command rotl in the monty file
*/

void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	if (head != NULL && (*head) != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		(*head)->prev = tmp;
		tmp->next = (*head);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*head) = tmp;
	}
}
