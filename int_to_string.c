#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_lent(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - gets a character printer to new string cont int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string
 * NULL if malloc fails
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_lent(temp, 10);

	if (num < 0 || num_1 < 0)
		length++; /* negative sign */
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @f: integer to get absoluter value for
 *
 * Return: unsigned int abs rep of i
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets lenght of buffer needed fo unsigned int
 * @num: number to get lenght  for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing lenght of busfeer
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all number ontaining atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only work up to 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: sixe of buffer in bytes
 *
 * Return: always void
 */
void fill_numbase_buffe(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representatio */
			buff[i] = rem + 87; /*10 will be a, 11 will be b, ..., */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
