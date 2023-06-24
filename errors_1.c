#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - prints a usage error message
 *
 * Return: EXIT_FAILURE always
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n"); /* Print the usage error message */
	return (EXIT_FAILURE); /* Return EXIT_FAILURE */
}

/**
 * malloc_error - prints a malloc error message
 *
 * Return: EXIT_FAILURE always
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n"); /* Print the malloc error message */
	return (EXIT_FAILURE); /* Return EXIT_FAILURE */
}

/**
 * f_open_error - prints a file opening error message
 * @filename: name of the file that failed to open
 *
 * Return: EXIT_FAILURE always
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename); /* Print the file opening error message */
	return (EXIT_FAILURE); /* Return EXIT_FAILURE */
}

/**
 * unknown_op_error - prints an unknown instruction error message
 * @opcode: opcode where the error occurred
 * @line_number: line number in the Monty bytecode file where the error happened
 *
 * Return: EXIT_FAILURE always
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode); /* Print the unknown instruction error message */
	return (EXIT_FAILURE); /* Return EXIT_FAILURE */
}

/**
 * no_int_error - prints an invalid monty_push argument error message
 * @line_number: line number in the Monty bytecode file where the error occurred
 *
 * Return: EXIT_FAILURE always
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	/* Print the invalid monty_push argument error message */
	return (EXIT_FAILURE); /* Return EXIT_FAILURE */
}
