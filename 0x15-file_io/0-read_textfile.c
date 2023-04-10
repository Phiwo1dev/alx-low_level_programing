#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text file and prints it to stdout
 * @filename: text file to be read
 * @letters: number of letters to read
 *
 * Return: number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, msk, rf;
	char *buf;

	fd = msk = rf = 0;
	if (!filename || !letters)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buf = malloc(sizeof(char) * letters + 1);
	if (!buf)
		return (0);
	rf = read(fd, buf, letters);
	if (rf < 0)
	{
		free(buf);
		return (0);
	}
	buf[letters] = '\0';
	msk = write(STDOUT_FILENO, buf, rf);
	if (msk <= 0)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(fd);
	return (rf);
}
