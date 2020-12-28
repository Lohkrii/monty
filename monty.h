#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "structs.h"

extern stack_t *head;

/* stack functions */
void push(stack_t **head, unsigned int line, char *n);
void pop(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);

/* math functions */
void add(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int line);
void mul(stack_t **head, unsigned int line);
void div_stack(stack_t **head, unsigned int line);
void mod(stack_t **head, unsigned int line);

/* Main functions */
void invalid_cmd_errmsg(char  *cmd, unsigned int ln_num, char *buffer, FILE *fp);
void open_file(char *monty_file);
void read_and_tokenize(FILE *fp);
void pall(stack_t **head, unsigned int line);
int check_cmd_no_arg(unsigned int line, char *token_1);
void free_stack(void);
void print(stack_t **head, unsigned int line);
void pint(stack_t **head,unsigned int line);
void check_cmd_arg(unsigned int ln_num, char *tok_1, char *tok_2, char *buf, FILE *fp);
void swap(stack_t **head, unsigned int line);
void add(stack_t **head, unsigned int line);
void div_stack(stack_t **head, unsigned int line);
void pchar(stack_t **head, unsigned int line);
void invalid_cmd_errmsg(char *cmd, unsigned int ln_num,char *buf, FILE *fp);
void pstr(stack_t **head, unsigned int line);
void rotl(stack_t **head, unsigned int line);
void rotr(stack_t **head, unsigned int line);

size_t stack_length(stack_t **head);

stack_t *check_int_arg(char *arg, char *buf, FILE *fp);
stack_t *create_stack(int n, char *buf, FILE *fp);

#endif /* MONTY_H */
