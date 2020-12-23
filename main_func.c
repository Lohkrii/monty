#include "monty.h"

/**
* check_int_arg - Checks if all the chars of the arg are int.
* @arg: Argument to check for ints.
* @buf: Pointer to where the argument is was initially stored.
* @fp: Pointer to an open monty file with all commands and args.
* Return: Pointer to new node with the arg value, NULL if failure.
*/

stack_t *check_int_arg(char *arg, char *buf, FILE *fp)
{
	int n, idx, is_neg = 0;
	stack_t *stack;

	if (arg != NULL && arg[0] == '-')
	{
		is_neg = -1;
		arg++;
	}
	if (arg != NULL && isdigit(*arg) != 0)
	{
		for (idx = 0; arg[idx] != '\0'; idx++)
		{
			if (isdigit(arg[idx]) == 0)
				return (NULL);
		}
		n = atoi(arg);
		if (is_neg == -1)
			n *= -1;
		stack = create_stack(n, buf, fp);
		return (stack);
	}
	return (NULL);
}


