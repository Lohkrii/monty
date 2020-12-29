#include "monty.h"

/**
* check_cmd_no_arg - Checks if arg is valid and runs it.
* @line_num: Number line in the command code.
* @token_1: Element to check.
* Return: O for success, -1 if invalid command.
*/

void check_cmd_no_arg(char *token_1, stack_t **stack, unsigned int line_num)
{
	int idx;

	instruction_t no_arg_func[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", div_stack},
			{"mul", mul},
			{"pchar", pchar},
			{"mod", mod},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr},
			{NULL, NULL}
			};
	for (idx = 0; no_arg_func[idx].opcode != NULL; idx++)
	{
		if (strcmp(token_1, no_arg_func[idx].opcode) == 0)
		{
			no_arg_func[idx].f(stack, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token_1);
	exit(EXIT_FAILURE);
}
