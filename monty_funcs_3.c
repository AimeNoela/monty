#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - does absolutely nothing for monty opcode "nop"
 * @stack: pointer to top mode node of a stack_t linked list
 * @line_number: current working line number of bytecode file
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Avoid unused variable warning */
	(void)line_number; /* Avoid unused variable warning */
}

/**
 * monty_pchar - print char in the top value node of stack_t linked list
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of monty bytecode file
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty")); /* Set error message if stack is empty */
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value out of range")); /* Set error message if value is out of range */
		return;
	}
	printf("%c\n", (*stack)->next->n); /* Print the character value */
}

/**
 * monty_pstr - print string contained in a stack_t linked list
 * @stack: pointer to top node of stack_t linked list
 * @line_number: current working line number
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next; /* Create a temporary pointer to the next node */

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n); /* Print the character value */
		tmp = tmp->next; /* Move to the next node */
	}
	printf("\n"); /* Print a new line */

	(void)line_number; /* Avoid unused variable warning */
}
