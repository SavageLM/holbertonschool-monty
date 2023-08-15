#include "monty.h"

/**
 * nop - does nothing
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void nop(stack_t **stack, unsigned int line_number, int strint)
{
	(void)stack;
	(void)line_number;
	(void)strint;
}

/**
 * pint - prints top of stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void pint(stack_t **stack, unsigned int line_number, int strint)
{
	(void)strint;
	(void)line_number;

	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints the stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void pall(stack_t **stack, unsigned int line_number, int strint)
{
	stack_t *tmp;
	(void)strint;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
