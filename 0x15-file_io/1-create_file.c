#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: name of the file to create
 * @text_content: text to write to the new file
 *
 * Return: 1 (Succes), -1 if it fails
 */
int create_file(const char *filename, char *text_content)

{
	int fd, w, len = 0;

	w = len = fd = 0;
	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd < 0)
			return (-1);
	while (text_content && text_content[len])
		len++;

	w = write(fd, text_content, len);
	if (w < 0)
		return (-1);
	close(fd);
	return (1);
}
