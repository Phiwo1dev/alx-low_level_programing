#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: body of the text to read
 * @letters: number of chars to be read
 *
 * Return: number of letters read, 0 if file NULL,
 * 0 if file cannot be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)

{
	int fd, err, rd;
	char *c;

	fd = err = rd = 0;
	if (!filename || !letters)
		return (0);
	fd = open(filename, O_RDONLY);
	
	if (fd < 0)
		return (0);
	c = malloc(sizeof(char) * letters);
	
	rd = read(fd, c, letters);
	err = write(STDOUT_FILENO, c, rd);

	free(c);
	close(fd);
	return (rd);
}
