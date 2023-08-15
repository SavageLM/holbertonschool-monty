#include "monty.h"

/**
 * main - Entry to functions
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char buffer[1024];
	unsigned int line_number = 1;
	FILE *file = fopen(argv[1], "r");

	quick_check(argc, argv[1], file);

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode = strtok(buffer, " \t\n");
		if (opcode && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				char *string = strtok(NULL, " \t\n");
				if (string && int_check(string))
				{
					int strint = atoi(string);
					find_function(&stack, opcode, line_number, strint);
				}
				else
				{
					fprintf(stderr,"L%d: usage: push integer\n", line_number);
					free_stack(stack);
					fclose(file);
					return EXIT_FAILURE;
				}
			}
			else
				find_function(&stack, opcode, line_number, 0);
		}
		line_number++;
	}
	free_stack(stack);
	fclose(file);
	return EXIT_SUCCESS;
}

/**
 * quick_check - Checks argument count and if a file exists
 * @argc: number of arguments
 * @file: file to check if it exists
 * @argv: array of arguments
 */

void quick_check(int argc,char *argv, FILE *file)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
/**
 * find_function -  Finds the matching function
 * @stack: stack functions are applied to
 * @opcode: Operation to search for
 * @line_number: line of file instruction is on
 * @strint: integer value of string
 */

void find_function(stack_t **stack, char *opcode, unsigned int line_number, int strint)
{
	int i;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	for (i = 0; functions[i].opcode != NULL; i++)
	{
		if (functions[i].opcode == opcode)
		{
			functions[i].f(stack, line_number, strint);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees all parts of the stack
 * @stack: stack to be freed
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * int_check - Checks if string can be an int
 * @string: string to check
 * Return: 1 if valid, 0 if not
 */

int int_check(const char *string)
{
	int i;

	if (string == NULL || string[0] == '\0')
		return (0);
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '+' || string[i] == '-')
			i++;
		if (!isdigit(string[i]))
			return (0);
	}
	return (1);
}
