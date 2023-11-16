#include "monty.h"
/**
*main - entry point
*@argc: argument count
*@argv: array of arguments
*Return: 0(Success)
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[LINE_MAX];/* Max that a line can hold */
	size_t line_no;
	stack_t *stack;
	instruction_t instructions[4];

	file = NULL;
	stack = NULL;

	/* array of instructions */
	instructions[4] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{NULL, NULL} /* array has to be null terminated */
	};
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file.m>\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_no++;
		/* tokennize and invoke appropriate function */
		processor(buffer, line_no, &stack, instructions);
		/* clear buffer for next line */
		memset(buffer, 0, sizeof(buffer));
	}
	/* close file */
	fclose(file);
	return (EXIT_SUCCESS);
}
