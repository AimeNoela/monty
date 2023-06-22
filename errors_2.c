#include "monty.c"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - prints por error message for empty stacks
 * @line_number: line number in script where error are
 *
 * Return: (EXIT_FAILURE) always
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u:can't pop on empty stack\n", line_manager);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints empty stack error message
 * @line_number: line number in bytecode file with rror
 *
 * Return: (EXIT_FAILURE) always
 */

int pint_error(unsigned int line_number)
{
	fpritf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * short_stack_error - print monty math function error message
 * for stack smaller than two nodes
 * @line_number: ine number in monty bytecodes file where error happened
 * @op: operation where error happened
 *
 * Return: (EXIT_FAILURE) always
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - print division error message for div by 0
 * @line_number: line number inmonty bytecodesfile where arrors are
 *
 * Return: (EXIT_FAILURE) always
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - prints pchar error message for empty stacks
 * and no-character value
 * @line_number: line number in monty bycodes file where error occured
 * @message: the corresponding error message printable
 *
 * Return: (EXIT_FAILURE) always
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

