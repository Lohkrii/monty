#include "monty.h"

/**
 * push - add an element to the top of stack
 * @head: top of stack
 * @line: line number
 * @n: data in element
 * Return: void or -1 if fail
 */
void push(stack_t **head, unsigned int line, char *n)
{
	stack_t *element = NULL;
	int i;

	if (n == NULL)
	{
		printf("L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - remove 1st element in stack
 * @head: stack
 * @line: line number
 * Return: void or exit
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
