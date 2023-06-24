#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds the top two values of a stack_t linked list
 * @stack: a pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		/* Set error message if stack is too short */
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	/* Perform addition on the top two values */
	monty_pop(stack, line_number); /* Remove the top value */
}

/**
 * monty_sub - subtracts the second value from the top of
 * a stack_t linked list by the top value
 * @stack: pointer to top node of stack_t linked list
 * @line_number: current working line number of monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		/* Set error message if stack is too short */
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	/* Perform subtraction on the top two values */
	monty_pop(stack, line_number); /* Remove the top value */
}

/**
 * monty_div - divides the second value from the top
 * of a stack_t linked list by the top value
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		/* Set error message if stack is too short */
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		/* Set error message if dividing by zero */
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	/* Perform division on the top two values */
	monty_pop(stack, line_number); /* Remove the top value */
}


/**
 * monty_mod - computes the modulus of the second value from the
 * top of stack_list linked list by the top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		/* Set error message if stack is too short */
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		/* Set error message if division by zero is attempted */
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	/* Compute the modulus of the second value by the top value */
	monty_pop(stack, line_number); /* Remove the top value */
}
