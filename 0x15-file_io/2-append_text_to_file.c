#include "main.h"

/**
 * append_text_to_file - A function that appends text at the end of a file
 * @filename: file to write text into
 * @text_content: text toappend into the file
 *
 * Return: 1 (Success), -1 if it fails
 */
int append_text_to_file(const char *filename, char *text_content)

{
	int f, w, len;

	f = w = len = 0;
	if (!filename)
		return (-1);
	else if (!text_content || !text_content[0])
		return (1);
	f = open(filename, O_WRONLY | O_APPEND);
	if (f < 0)
		return (-1);
	while (text_content[len])
		len++;
	w = write(f, text_content, len);
	if (w < 0)
		return (-1);
	close(f);
	return (1);
}
