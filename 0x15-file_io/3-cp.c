#include "main.h"
#include <stdlib.h>
#include <stdio.h>

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
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - Closes file a descriptor.
 * @fd: The file descriptor to close
 */
void close_file(int fd)

{
	int s;

	s = close(fd);
	if (s == -1)
	{
		dprintf(STDERR_FILENO, "Error: closing failed %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies content of one file into anaother.
 * @argc: argument count
 * @argv: argument values
 *
 * Return: 0 (Success)
 *
 */
int main(int argc, char *argv[])

{
	int file_from, file_to, rd_len, fd;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	rd_len = read(file_from, buf, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || rd_len == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: unable to read file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		fd = write(file_to, buf, rd_len);
		if (file_to == -1 || fd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: failed to write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		rd_len = read(file_from, buf, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd_len > 0);

	free(buf);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
