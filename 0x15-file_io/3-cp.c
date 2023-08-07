#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - a function allocates 1024 bytes for a buffer.
 * @file: destination for contents in buffer
 *
 * Return: new buffer
 */
char *create_buffer(char *file)

{
	char *buf;

		buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - a function that closes file descriptors.
 * @fd: file descriptor to be closed.
 */
void close_file(int fd)

{
	int f;

	f = close(fd);

	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 *  main - Copies the contents of a file into another file.
 * @argc: Argument count
 * @argv: Argument values
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])

{
	int file_from, file_to, r, err;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	r = read(file_from, buf, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		err = write(file_to, buf, r);
		if (file_to == -1 || err == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		r = read(file_from, buf, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(buf);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
