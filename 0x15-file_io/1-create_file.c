#include "main.h"
#include <stdio.h>

/**
 * create_file - This function creates a file
 * @filename: Name of the file
 * @text_content: A NULL terminated string to write to the file
 *
 * Return: 1 if success or -1 if failure
 */

int create_file(const char *filename, char *text_content)
{
	int w, fd, count = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		do {
			count++;
		} while (text_content[count] != '\0');
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, count);

	if (fd == -1 || w == -1)
	{
		return (-1);
	}
	close(fd);

	return (1);
}

