#include "monty.h"

/**
* check_cmd_no_arg - Checks if arg is valid and runs it.
* @line_num: Number line in the command code.
* @token_1: Element to check.
* Return: O for success, -1 if invalid command.
*/

int check_cmd_no_arg(unsigned int line_num, char *token_1)
{
	int idx;

	instruction_t no_arg_func[] = {
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
			no_arg_func[idx].f(&head, line_num);
			return (0);
		}
	}
	return (-1);
}

/**
* invalid_cmd_errmsg - Frees buffer, closes file and print error.
* @cmd: Invalid command to print error for.
* @ln_num: Number line of the command in bytecode monty file.
* @buffer: Pointer to the command string.
* @fp: FILE type pointer to the open monty file.
*/

void invalid_cmd_errmsg(char *cmd, unsigned int ln_num, char *buffer, FILE *fp)
{
	if (strcmp(cmd, "push") == 0)
	{
		printf("L%d: usage: push integer\n", ln_num);
		free(buffer);
		fclose(fp);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("L%d: unknown instruction %s\n", ln_num, cmd);
	free_stack();
	free(buffer);
	fclose(fp);
	exit(EXIT_FAILURE);
}

/**
* open_file - Opens the file.
* @monty_file: File to open.
*/

void open_file(char *monty_file)
{
	FILE *fp;
	/*check whether file is accessible */
	if (access(monty_file, F_OK) != 0)
	{
		printf("Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	/*open file to read */
	fp = fopen(monty_file, "r");/*open file to read*/
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	read_and_tokenize(fp);/*call function to read to buffer and tokenize*/
}

/**
* read_and_tokenize - Tokinizes a line.
* @fp: FILE struct pointer to the open file.
*/

void read_and_tokenize(FILE *fp)
{
	char *buffer, *delim;
	char *token_1, *token_2;
	size_t n;
	unsigned int line_num;

	delim = " \t\n";
	token_1 = token_2 = buffer = NULL;
	for (line_num = 1; getline(&buffer, &n, fp) != -1; line_num++)
	{
		token_1 = strtok(buffer, delim);/*tokenize first command*/
		if (token_1 == NULL || token_1[0] == '#')
			continue;
		token_2 = strtok(NULL, delim);/*tokenize argument for the command*/
		if (check_cmd_no_arg(line_num, token_1) == -1)
		{
			check_cmd_arg(line_num, token_1, token_2, buffer, fp);
		}
	}
	free(buffer);
	fclose(fp);
	free_stack();
}

/**
* create_stack - Creates a new stack and populates n data.
* @n: Data for n element of the new stack struct.
* @buf: Pointer to the string of commands in the file.
* @fp: Pointer to the open file.
* Return: Pointer to the stack.
*/

stack_t *create_stack(int n, char *buf, FILE *fp)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		free(buf);
		fclose(fp);
		free_stack();
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack->n = n;
	return (stack);
}
