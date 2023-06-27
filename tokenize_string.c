#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_lenght(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - taking a string and separting its words
 *
 * @str: strings to be separated into words
 * @delims: delimitators to use to delimit words
 *
 * Return: 20 arrays of pointer to each wd
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, i = 0;

	if (str == NULL || !str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordlen = get_word_lenght(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordlen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* setting end of str */
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* for iteration last element is Nnull */
	return (words);
}

/**
 * is_delim - checking if streams has deliminator char
 * @ch: character to consider
 * @delims: pointer to null terminated array
 * Return: 1 on success and 0 on failure
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (i);
		i++;
	}
	return (0);
}

/**
 * get_word_length - getting thelength of cur word in str
 * @str: string for the word length
 * @delims: delimiors usedfor words
 *
 * Return: word length of current word
 */
int get_word_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wlen++;
		}
		if (wlen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}

/**
 * get_word_count - getting the count of words of a string
 * @str: string to consider
 * @delims: delimitators to the words
 *
 * Return: word count of the string
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending - 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - getting the next words i string
 * @str: tring
 * @delims: deliminators
 *
 * Return: pointer to first char of next word
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
