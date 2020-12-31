#include "monty.h"
var_t var;

/**
* main - Monty initializer.
* @argc: Number of arguments received.
* @argv: Pointer to an array of string of arguments.
* Return: 0 for Succes, 1 if failed.
*/

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	unsigned int line = 0;
	stack_t *stack;
	char *cmd_ptr = NULL, *cmd = NULL;
	size_t n = 0;

	var.queue = 0;
	var.head_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");/*open file to read*/
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&cmd_ptr, &n, fp) != -1)
	{
		line++;
		cmd = strtok(cmd_ptr, " \t\n\r");

		if (cmd != NULL && cmd[0] != '#')
		{
			check_cmd_no_arg(cmd, &stack, line);
		}
	}
	on_exit(free_lineptr, &cmd_ptr);
	on_exit(free_stk, &stack);
	on_exit(fp_close, fp);
	exit(EXIT_SUCCESS);
}
