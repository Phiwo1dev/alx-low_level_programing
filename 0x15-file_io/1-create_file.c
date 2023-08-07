#include "main.h"

/**
 * create_file - function that will create a new file with content.
 * @filename: the file to create
 * @text_content: text to write to the new file
 *
 * Return: 0 (Success), 1 for error
 */
int create_file(const char *filename, char *text_content)

{
	int w, len, f;

	w = len = f = 0;
	if (!filename)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		if (f < 0)
			return (-1);
	while (text_content && text_content[len])
		len++;

	w = write(f, text_content, len);
	if (w < 0)
		return (-1);
	close(f);
	return (1);
}
