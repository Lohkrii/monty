#include "monty.h"

/**
 * pall - Prints the stack starting from the top.
 * @head: First item in the stack.
 * @line: Line number of the command file.
 */

void pall(stack_t **head, unsigned int line)
{
	stack_t *iterator;
	(void)line;

	iterator = *head;
	while(iterator)
	{
		printf("%d\n", iterator->n);
		iterator = iterator->next;
		if (iterator == *head)
			return;
	}
}

/**
 * pint - Prints the value at the head of the stack.
 * @head: First item in the stack.
 * @line: Line number of the command file.
 */

void pint(stack_t **head, unsigned int line)
{
	if (head == NULL || (*head) == NULL)
	{
		fprintf(stderr, "L%d: Can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pchar - Prints the value at the head of the stack.
 * @head: First item in the stack.
 * @line: Line number of the command file.
 */

void pchar(stack_t **head, unsigned int line)
{
	int value;

	if (head == NULL || (*head) == NULL)
	{
		fprintf(stderr, "L%d: cant pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	if (value >= 65 && value <= 90)
	{
		printf("%c\n", value);
	}
	else if (value >= 97 && value <= 122)
	{
		printf("%c\n", value);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
       		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - Prints the stack in string format.
 * @head: First item on the stack.
 * @line: Line number of the command file.
 */

void pstr(stack_t **head, unsigned int line)
{
	stack_t *iterator;
	int value;
	(void) line;

	if (head == NULL || (*head) == NULL)
	{
		printf("/n");
	}
	else
	{
		iterator = *head;
		for (;iterator != NULL && iterator->n != 0;)
		{
			value = iterator->n;
			if (value >= 65 && value <= 122)
			{
				putchar(value);
				iterator = iterator->next;
			}
			else if (value >= 97 && value <= 122)
			{
				putchar(value);
				iterator = iterator->next;
			}
			else
				break;
		}
		putchar('\n');
	}
}
