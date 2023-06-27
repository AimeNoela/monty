#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - entry point for the Monty interpreter
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers representing the arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	/* Check if the correct number of arguments is provided */

	script_fd = fopen(argv[1], "r");
	/* Open the Monty bytecode file in read mode */
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	/* Return error if the file cannot be opened */

	exit_code = run_monty(script_fd);
	/* Execute the Monty bytecode instructions */
	fclose(script_fd); /* Close the Monty bytecode file */
	return (exit_code); /* Return the exit code */
}
