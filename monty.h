#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "structs.h"

/* stack functions */
void push(stack_t **head, unsigned int line, char *n);
void pop(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);

/* math functions */
void add(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void div_stack(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);

#endif /* MONTY_H */
