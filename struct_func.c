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
	for (i = 0; n[i] != '\0'; i++)
	{
		if (isdigit(n[i]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	element->n = atoi(n);
	element->prev = NULL;
	element->next = NULL;
	if (*head != NULL)
	{
		element->next = *head;
		(*head)->prev = element;
	}

	*head = element;
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

/**
 * swap - swaps the value of the top two elements on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void, exit with -1 on failure
 */
void swap(stack_t **head, unsigned int line)
{
	int temp;
	int temp2;

	if (stack_length(head) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	temp2 = (*head)->next->n;
	(*head)->n = temp2;
	(*head)->next->n = temp;
}
