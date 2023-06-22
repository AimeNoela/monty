#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - does absolutely nothing for monty opcode "nop"
 * @stack: pointer to top mode node of a stack_t linked list
 * @line_number: current working line number of bytecode fil
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - print char in the top vaues
 * node of stack_t linked list
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of monty bytecods file
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{ set_op_tok_error(pchar_error(line_number,
				"value out of range"));
	return;
	}
	printf("%c\n", (*stac)->next->n);
}

/**
 * monty_pstr - print string contained in a stack_t linked list
 * @stack: ponter
 * @line_number: current working line number
 */
monty_nop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");

	(void)line_number;
}

