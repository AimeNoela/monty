#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - freing a sta_t stack
 * @stack: pointer to top or
 * bottom queue of stack
 *
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack -initialising a stack_t with beginning
 * stack and ending queue noe
 * @stack: pointer to uninitialised stack_t
 *
 * Return: (EXIT_FAILURE)if erro accir
 * (EXIT_SUCCESS) otherwise
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = stack;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - checking if stack_t linked list is in stack or queue mode
 * @stack: pointer to top stack or bottow queue
 * of a stack_t linked list
 *
 * Return: STACK(0) if the stack is in stack mode
 * QUEUE (1) if stack_t is in queue mode
 * or 2 othewise
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
