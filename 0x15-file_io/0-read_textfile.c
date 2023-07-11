#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: text to print
 * @letters: number of letters to print
 *
 * Return: 0 if function fails or is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)

{
	ssize_t fd, rd, err;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	err = read(fd, buf, letters);
	rd = write(STDOUT_FILENO, buf, err);

	free(buf);
	close(fd);
	return (rd);
}
