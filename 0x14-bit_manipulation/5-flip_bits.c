#include "main.h"

/**
 * flip_bits - This function returns the number of bits you would need to flip
 * to get from one number to another
 * @n: Thi is the bits to be flipped
 * @m: we are flipping to get here
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int t, k;

	t = n ^ m;

	k = 0;

	do {
		k += (t & 1);
		t >>= 1;
	} while (t != 0);

	return (k);
}

