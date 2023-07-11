#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: name of a file to write text into.
 * @text_content: string to append to the file
 *
 * Return: 1 (Success), -1 if it fails
 */
int append_text_to_file(const char *filename, char *text_content)

{
	int a, w, len = 0;

	if (!filename)
		return (-1);
	else if (!text_content || !text_content[0])
		return (1);
	a = open(filename, O_WRONLY | O_APPEND);
	if (a < 0)
		return (-1);
	while (text_content[len])
		len++;
	w = write(a, text_content, len);
	if (w < 0)
		return (-1);
	close(a);
	return (1);
}
