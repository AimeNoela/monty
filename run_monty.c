#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_ line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_token - free the global op_tok array of a string
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);
	free(op_toks);
}

/**
 * token_arr_len - gets the lenght of current op_toks
 *
 * Return: lenght of current op_toks
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty - check if line read from getline only contains delimination
 * @line: a ponter
 * @delims: a string of deiminatr
 *
 * Return: if the line only contains deliminato - 1
 * other wise 0
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[1]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - mathes apacode with its cerresponding function
 * @opccode: oppcode to matc
 *
 * return: pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{

	instruction_t op_funcs[] = {


