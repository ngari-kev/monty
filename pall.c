#include "monty.h"
/**
*pall - prints all values in a stack
*@stack: pointer to top element of the stack
*@value: line number
*/
void pall(stack_t **stack, unsigned int value)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	if (stack == NULL)
	{
		printf("Line no: %d: stack is empty\n", value);
	}
}
