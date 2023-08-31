#include "main.h"

/**
 * get_endianness - Thi function checks the endianness
 *
 * Return: 0 if big endian 1 if little endian
 */

int get_endianness(void)
{
	int t = 2;

	if (t & 1)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

