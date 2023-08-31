#include "main.h"

/**
 * clear_bit - Thi function sets value of a bit to 0 at a given index
 * @n: pointer to integer
 * @index: index given
 *
 * Return: 1 if successful, -1 otherwise
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int count = 1;

	if (index > 64)
	{
		return (-1);
	}

	count = ~(count << index);
	*n = *n & count;

	return (1);
}

