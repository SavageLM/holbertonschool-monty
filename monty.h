#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, int strint);
}instruction_t;

/*Prototypes*/
int main(int argc, char *argv[]);
void quick_check(int argc,char *argv, FILE *file);
void find_function(stack_t **stack, char *opcode, unsigned int line_number, int strint);
void free_stack(stack_t *stack);
int int_check(const char *string);
void nop(stack_t **stack, unsigned int line_number, int strint);
void pint(stack_t **stack, unsigned int line_number, int strint);
void pall(stack_t **stack, unsigned int line_number, int strint);
void add(stack_t **stack, unsigned int line_number, int strint);
void swap(stack_t **stack, unsigned int line_number, int strint);
void push(stack_t **stack, unsigned int line_number, int strint);
void pop(stack_t **stack, unsigned int line_number, int strint);

#endif
