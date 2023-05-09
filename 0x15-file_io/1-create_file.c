#include "main.h"

/**
 * create_file - a function that creates a file containing text
 * @filename: name of the file to create
 * @text_content: text to write in the file
 *
 * Return: 1 (success), -1 for failure
 */
int create_file(const char *filename, char *text_content)

{
	int fd, j, w;

	fd = j = w = 0;
	if (!filename)
		return (-1);

	w = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		if (w < 0)
			return (-1);
	while (text_content && text_content[j])
		j++;

	fd = write(w, text_content, j);
	if (fd < 0)
		return (-1);
	close(w);
	return (1);
}
