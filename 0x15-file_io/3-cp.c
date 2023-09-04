#include "main.h"
#include <stdio.h>
#define BUF_SIZE 1024


/**
 * error_with_98 - This function checks error 98
 * @fd: File to check if there is an error
 * @buffer: the buffer
 * @argv: The arguments within the function
 *
 * Return: Void
 */

void error_with_98(int fd, char *buffer, char *argv)
{

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
		free(buffer);
		exit(98);
	}
}

/**
 * error_with_99 - This function checks for error 99
 * @fd: This is the file to be checked
 * @buffer: the buffer
 * @argv: argument in the function
 *
 * Return: Void
 */
void error_with_99(int fd, char *buffer, char *argv)
{
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
		free(buffer);
		exit(99);
	}
}

/**
 * close_error - This function checks for error 100
 * @fd: the file to be checked
 * @buffer: the buffer
 *
 * Return: Void
 */
void close_error(int fd, char *buffer)
{
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		free(buffer);
		exit(100);
	}
}

/**
 * main - Function entry point
 * @argc: This is the number of arguments in the function
 * @argv: This is a pointer to the arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *buffer;
	int fd, file, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (0);

	file = open(argv[1], O_RDONLY);
	error_with_98(file, buffer, argv[1]);
	fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	error_with_99(fd, buffer, argv[2]);
	do {
		r = read(file, buffer, BUF_SIZE);
		if (r == 0)
			break;
		error_with_98(r, buffer, argv[1]);
		w = write(fd, buffer, r);
		error_with_99(w, buffer, argv[2]);
	} while (w >= BUF_SIZE);
	r = close(fd);
	close_error(r, buffer);
	r = close(file);
	close_error(r, buffer);
	free(buffer);
	return (0);
}

