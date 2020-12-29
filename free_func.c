#include "monty.h"

void free_stk(int status, void *line)
{
	stack_t **head;
	stack_t *next;
	(void)status;

	head = (stack_t **)line;
	if (*head)
	{
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
	}
	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	var.head_len = 0;
}
void fp_close(int status, void *line)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) line;
	fclose(fs);
}
void free_lineptr(int status, void *line)
{
	char **lineptr = line;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}
