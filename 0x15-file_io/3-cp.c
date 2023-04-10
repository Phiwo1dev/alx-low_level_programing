#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer storing chars.
 *
 * Return: A pointer to the new buffer.
 */
char *create_buffer(char *file)

{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (b);
}
/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor.
 */
void close_file(int fd)
{
	int x;

	x = close(fd);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file into another file.
 * @argc:  argument count.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int a, z, i, w;
	char *b;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	b = create_buffer(argv[2]);
	a = open(argv[1], O_RDONLY);
	i = read(a, b, 1024);
	z = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
	if (a == -1 || i == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		free(b);
		exit(98);
	}
	w = write(z, b, i);
	if (z == -1 || w == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		free(b);
		exit(99);
	}

	i = read(a, b, 1024);
	z = open(argv[2], O_WRONLY | O_APPEND);

	} while (i > 0);
	free(b);
	close_file(a);
	close_file(z);

	return (0);
}
