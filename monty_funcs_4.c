#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - rotates the top value of a stack_t linked list to the bottom
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of the monty bytecode file
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack; /* Update the previous node of the second element */
	(*stack)->next = top->next; /* Update the next node of the top element */
	bottom->next = top; /* Move the top element to the bottom */
	top->next = NULL; /* Set the next node of the top element as NULL */
	top->prev = bottom; /* Update the previous node of the top element */

	(void)line_number;
}

/**
 * monty_rotr - rotates the bottom value of a stack_t linked list to the top
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of the monty bytecode file
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	/* Set the next node of the second-to-last node as NULL */
	(*stack)->next = bottom; /* Update the next node of the top element */
	bottom->prev = *stack; /* Update the previous node of the bottom element */
	bottom->next = top; /* Move the bottom element to the top */
	top->prev = bottom; /* Update the previous node of the top element */

	(void)line_number;
}

/**
 * monty_stack - converts the queue to a stack
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of the monty bytecode file
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK; /* Set the 'n' value of the top element as STACK */

	(void)line_number;
}

/**
 * monty_queue - converts the stack to a queue
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of the monty bytecode file
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE; /* Set the 'n' value of the top element as QUEUE */

	(void)line_number;
}
