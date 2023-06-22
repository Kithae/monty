#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - a structure
 * @n: an integer
 * @prev: a pointer
 * @next: a pointer
 *
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - a structure
 * @opcode: an opcode
 * @f: a function for handling the opcode
 *
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - a structure
 * @av: a char name
 * @ac: total arguments
 * @line_number: an int
 *
*/
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - a structure
 * @line: file line
 * @words: a parsed line
 * @stack: a pointer
 * @fptr: a pointer
 * @qflag: a flag
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define ADD_FAIL "L%u: can't add, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define DIV_ZERO "L%u: division by zero\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define USAGE "USAGE: monty file\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"
#define UNKNOWN "L%u: unknown instruction %s\n"

/* stringtow.c */
int word_count(char *s);
char **stringtow(char *str);
void everything_free(char **args);

/* read_func.c */
void (*read_func(char **parsed))(stack_t **, unsigned int);
void handler_push(stack_t **stack, unsigned int line_number);
void handler_pall(stack_t **stack, unsigned int line_number);

/* handlechar.c */
void handler_pchar(stack_t **stack, unsigned int line_number);
void handler_pstr(stack_t **stack, unsigned int line_number);

/* 1handler.c */
void handler_pint(stack_t **stack, unsigned int line_number);
void handler_pop(stack_t **stack, unsigned int line_number);
void handler_swap(stack_t **stack, unsigned int line_number);
void handler_add(stack_t **stack, unsigned int line_number);
void handler_nop(stack_t **stack, unsigned int line_number);

/* allfree.c */
void all_free(int all);

/* 3handler.c */
void handler_rotl(stack_t **stack, unsigned int line_number);
void handler_rotr(stack_t **stack, unsigned int line_number);
void handler_stack(stack_t **stack, unsigned int line_number);
void handler_queue(stack_t **stack, unsigned int line_number);

/* monty.c */
void mymonty(args_t *args);

/* 2handler.c */
void handler_sub(stack_t **stack, unsigned int line_number);
void handler_div(stack_t **stack, unsigned int line_number);
void handler_mul(stack_t **stack, unsigned int line_number);
void handler_mod(stack_t **stack, unsigned int line_number);

#endif
