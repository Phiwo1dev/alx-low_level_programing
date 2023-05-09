#include "main.h"
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - writes buffer to a file.
 * @file: name of file to write into
 *
 * Return: new buffer
 */
char *create_buffer(char *file)

{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
	printf(STDERR_FILENO, "Error: unable to write to %s\n", file);
		exit(99);
	}

	return (buf);
}
/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)

{
	int i;

	i = close(fd);

	if (i == -1)
	{
	dprintf(STDERR_FILENO, "Error: unable to close fd %d\n", fd);
		exit(100);
	}
}

/**
 *  main - Copies the contents of one file into another file.
 * @ac: argument count
 * @av: argument value
 *
 * Return: 0 (success)
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int ac, char *av[])
{
	int start, end, j, i;
	char *buf;

	if (ac != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buffer(av[2]);
	start = open(av[1], O_RDONLY);
	j = read(start, buf, 1024);
	end = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (start == -1 || j == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: unable to read from file %s\n", av[1]);
			free(buf);
			exit (98);
		}

		i = write(end, buf, j);
		if (end == -1 || i == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: unable to write to %s\n", av[2]);
			free(buf);
			exit(99);
		}

	j = read(start, buf, 1024);
	end = open(av[2], O_WRONLY | O_APPEND);

	} while (j > 0);

	free(buf);
	close_file(start);
	close_file(end);

	return (0);
}
