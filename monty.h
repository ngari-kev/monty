#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******** CONSTANTS *********/
#define LINE_MAX 1024

/******* STRUCTURES *********/

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
} stack_t;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/************************ FUNCTION PROTOTYPES *************************/
void processor(char *line, unsigned int line_no, stack_t **stack, instruction_t *instructions);
void push(stack_t **stack, unsigned int value);
void pop(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
#endif
