#include "monty.h"

/**
 * pall - Prints the stack starting from the top.
 * @head: First item in the stack.
 * @line_num: Line number of the command file.
 */

void pall(stack_t **head, unsigned int line_num)
{
	stack_t *iterator;
	(void)line_num;

	iterator = *head;
	for (;iterator;)
	{
		printf("%d\n", iterator->n);
		iterator = iterator->next;
	}
}

/**
 * pint - Prints the value at the head of the stack.
 * @head: First item in the stack.
 * @line_num: Line number of the command file.
 */

void pint(stack_t **head, unsigned int line_num)
{
	if (head == NULL || (*head) == NULL)
	{
		printf("L%d: Can't pint, stack empty\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pchar - Prints the value at the head of the stack.
 * @head: First item in the stack.
 * @line_num: Line number of the command file.
 */

void pchar(stack_t **head unsigned int line_num)
{
	int value;

	if (head == NULL || (*head) == NULL)
	{
		printf("L%d: cant pchar, stack empty\n", line_num);
		free_stack();
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
		print("L%d: can't pchar, value out of range\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - Prints the stack in string format.
 * @head: First item on the stack.
 * @line_num: Line number of the command file.
 */

void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *iterator;
	int value;
	(void) line_num;

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
