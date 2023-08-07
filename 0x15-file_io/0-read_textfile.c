#include "main.h"
#include <stdlib.h>


/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: text file to read
 * @letters: number of chars to read
 *
 * Return: actual number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)

{
	char *b;
	ssize_t fd;
	ssize_t rd;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	t = read(fd, b, letters);
	rd = write(STDOUT_FILENO, b, t);

	free(b);
	close(fd);
	return (rd);
}
