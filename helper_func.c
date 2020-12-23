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
* check_arg_func - Checks if an arg is valid and call corresponding function.
* @ln_num: Number line of the arg in bytecode file
* @command: first argument to check
* @arg: second argument to check
* @buf: Pointer to string of commands from bytecode monty file
* @fp: Pointer to open monty file
*/
void check_cmd_arg(unsigned int ln_num,
		char *command, char *arg, char *buf, FILE *fp)
{
	int idx;
	stack_t *stack = NULL;

	instruction_t arg_func[] = {{"push", push},
			{NULL, NULL}
			};
	for (idx = 0; arg_func[idx].opcode != NULL; idx++)
	{
		/*check if command is a valid command */
		if (strcmp(command, arg_func[idx].opcode) == 0)
		{
			stack = check_int_arg(arg, buf, fp);
			if (stack != NULL)
				arg_func[idx].f(&stack, ln_num);
			else/*invalid arg to command is given*/
				invalid_cmd_errmsg(command, ln_num, buf, fp);
		}
		else/*invalid command is given*/
			invalid_cmd_errmsg(command, ln_num, buf, fp);
	}
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
