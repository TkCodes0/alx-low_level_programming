#include "main.h"


/**
 * binary_to_uint - This function converts binary to unsigned int
 * @b: This is a constant char
 *
 * Return: The converted number or 0 if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int t, res;

	if (b == NULL)
	{
		return (0);
	}

	t = 0, res = 0;

	do {
		if (b[t] == '0')
		{
			res = res * 2;
		}
		else if (b[t] == '1')
		{
			res = res * 2 + 1;
		}
		else
			return (0);
		t++;
	} while (b[t] != '\0');

	return (res);
}

