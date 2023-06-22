#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - rotate the top value stack_t liked list to bottom
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of monty bytecode file
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

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - rotate bottom value of stack_t linked line to top
 * @stack: pointer the top mode node of stack_t linked list
 * @line_number: current working line number of monty bytecodes file
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stock)->next->next == NULL)
		return;

	top = (*stck)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - covert queu to stack
 * @stack: ponter to top mode of stack_t list
 * @line_number: current working line number o monty bytecodes file
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stackk)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - converts stack to queue
 * @stack: pointer to mode node of stack_t linked list
 * @line_number: current working line number of monty bytecode file
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
