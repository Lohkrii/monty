#include "monty.h"

/**
 * searchNumber - searches for a number
 * @s: number to be searched for
 * Return: 1 if found else 0
 */

static int searchNumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;
		if (isdigit(s[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - add an element to the top of stack
 * @head: top of stack
 * @line: line number
 * @n: data in element
 * Return: void or -1 if fail
 */

void push(stack_t **head, unsigned int line)
{
       	int i;
	char *cmd;

	cmd = strtok(NULL, "\n\t\r ");
	if (cmd == NULL || searchNumber(cmd))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	i = atoi(cmd);
      	if (add_node(head,i) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.head_len++;
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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * add_node - adds a node to stack
 * @head: head to a linked list
 * @n: data of new node
 * Return: new node, or null
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*head == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*head)->prev->next = new;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		new->next = *head;
	}
	if (var.queue == STACK || var.head_len == 0)
		*head = new;
        return (new);
}

/**
 * swap - swaps the value of the top two elements on the stack
 * @stack: pointer to stack
 * @line: line number of instruction
 * Return: void, exit with -1 on failure
 */
void swap(stack_t **head, unsigned int line)
{
	int temp;
	int temp2;

	if (stack_length(head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	temp2 = (*head)->next->n;
	(*head)->n = temp2;
	(*head)->next->n = temp;
}
/**
 * nop - does nothing
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
