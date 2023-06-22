#include "monthy.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - prints usage error message
 * Return: (EXIT_FAILURE) always
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - print malloc error message
 *
 * Return: (EXIT_FAILURE) always
 */
int malloc_error(void)
{fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - print file opening error message
 * @filename: name of failed to open file
 *
 * Return: (EXIT_FAILURE) always
 */

int f_open_error(char *filename)
{
	fprintf(stderr, "Error: can't opn file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints unknown instruction error message
 * @opcode: Opcode where error accur
 * @line_number: line number in monty bycode file where erros happened
 *
 * Return: (EXIT_FAILURE) always
 */
int unkown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid monty_push argument error message
 * @line_number: line number in monthy bycodes file wre error are
 *
 * Return: (EXIT_FAILURE) always
 */
int no_int_error(unsigned int line_numbr)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

