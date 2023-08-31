#include "main.h"

/**
 * get_bit - This function returns the value of
 * a bit at a given index
 * @n: This is an unsigned long int
 * @index: This is theindex given
 *
 * Return: index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int count = 1, val;

	if (n == 0)
		return (0);

	/** unsigned int 64 bytes*/

	if (index > 64)
	{
		return (-1);
	}

	count = count << index;

	if (n & count)
	{
		val = 1;
	}
	else
	{
		val = 0;
	}

	return (val);
}

