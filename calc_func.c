#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @head: Stack pointer.
 * @line_num: Line number in command file.
 */

void add(stack_t **head, unsigned int line_num)
{
	int product = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	product = (*head)->n + (*head)->next->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = product;
}

/**
 * sub - Subtracts the top two elements from the stack
 * @head: Stack pointer.
 * @line_num: Line number in command file.
 */

void sub(stack_t **head, unsigned int line_num)
{
	int product = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	product = (*head)->next->n - (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = product;
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @head: Stack pointer.
 * @line_num: Line number in command file.
 */

void mul(stack_t **head, unsigned int line_num)
{
	int product = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	product = (*head)->n * (*head)->next->n;
	(*head) = (*head)->next;
	(*head)->n = product;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
* div_stack - Divides the top two elements of the stack.
* @head: Stack pointer.
* @line_num: Line number of the comman`d file.
*/

void div_stack(stack_t **head, unsigned int line_num)
{
	int product = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	product = (*head)->next->n / (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = product;
}

/**
* mod - Computes the rest of division of the second element by first element.
* @head: Stack pointer.
* @line_num: Line number of the command file.
*/

void mod(stack_t **head, unsigned int line_num)
{
	int product = 0;

	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	product = (*head)->next->n % (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = product;
}
