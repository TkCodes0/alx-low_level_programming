#include "main.h"

/**
 * read_textfile - This function reads a text file and prints
 * it to the POSIX standard output.
 * @filename: This is a pointer to the file
 * @letters: The letters tobe read and printed
 *
 * Return: number of letters function reads and prints otherwise 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	size_t r, w;
	int op;

	if (filename == NULL)
	{
		return (0);
	}

	/* allocting memory, if it fails return 0*/

	b = malloc(sizeof(char) * letters);
	if (b == NULL)
	{
		return (0);
	}

	op = open(filename, O_RDONLY);

	/* if the file can not be opened or read, return 0 */
	if (op == -1)
	{
		return (0);
	}

	/* time to process */

	r = read(op, b, letters);
	w = write(STDOUT_FILENO, b, r);

	free(b);
	close(op);
	return (w);
}

