#include <stdlib.h>
#include "monty.h"
/**
 *  get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 * Return: character pointer to newly created string. NULL if malloc fails.
*/
char *get_int_(int num)
{
	unsigned int tmp;
	int len = 0;
	long num_ll = 0;
	char *rett;

	tmp = abs_(num);
	len = get_buff_len(tmp, 10);

	if (num < 0 || num_ll < 0)
		len++;
	rett = malloc(len + 1);
	if (!rett)
		return (NULL);

	fill_buff(tmp, 10, rett, len);
	if (num < 0 || num_ll < 0)
		rett[0] = '-';

	return (rett);
}

/**
 * abs_ - gets the absolute value of an integer
 * @a: integer to get absolute value of
 * Return: unsigned integer abs rep of i
*/
unsigned int abs_(int a)
{
	if (a < 0)
		return (-(unsigned int)a);
	return ((unsigned int)a);
}

/**
 *  get_buff_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number rep
 * Return: integer containing length of buffer
*/
int get_buff_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 * Return: always void.
*/
void fill_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int mod, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		mod = num % base;
		if (mod > 9)
			buff[i] = mod + 87;
		else
			buff[i] = mod + '0';
		num /= base;
		i--;
	}
}
