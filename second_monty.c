#include "monty.h"

/**
 * pop - Removes an element from the stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void pop(stack_t **stack, unsigned int line_number, int strint)
{
	stack_t *tmp;
	(void)strint;
	(void)line_number;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;

		if (*stack)
			(*stack)->prev = NULL;
		free(tmp);
	}

	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * add - Adds top two elements of the stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void add(stack_t **stack, unsigned int line_number, int strint)
{
	(void)strint;
	int total;

	if (*stack && (*stack)->next)
	{
		total = (*stack)->n + (*stack)->next->n;
		pop(stack, line_number, strint);
		(*stack)->n = total;
	}

	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * push - pushed an element on to the stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void push(stack_t **stack, unsigned int line_number, int strint)
{
	(void)line_number;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = strint;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new

	*stack = new;
}

/**
 * swap - swaps top two elements of a stack
 * @stack: stack to perform function on
 * @line_number: line of operation to perform
 * @strint: strint turned to an int
 */

void swap(stack_t **stack, unsigned int line_number, int strint)
{
	(void)strint;
	(void)line_number;
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
