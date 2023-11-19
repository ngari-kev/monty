#include "monty.h"

/**
 * processor - Tokenize and execute instructions based on opcode.
 * @line: Input line containing the opcode.
 * @line_no: Line number being processed.
 * @stack: Double pointer to the head of the stack.
 * @instructions: Array of opcode and function pairs.
 */
void processor(char *line, unsigned int line_no, stack_t **stack, instruction_t *instructions)
{
	char *token;
	char *opcode;
	int value, i;

	/* Tokenize the line */
	token = strtok(line, " \t\n");
	if (token == NULL || token[0] == '#')
	{
		/* Ignore empty lines or comments */
		return;
	}
	opcode = token;
	token = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (token == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		value = atoi(token);
		push(stack, value);
	}
	else
	{
		/* Find the opcode and execute the corresponding function */
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_no);
				return;
			}
		}
		/* Opcode not found in the instructions array */
		fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
		exit(EXIT_FAILURE);
	}
}
