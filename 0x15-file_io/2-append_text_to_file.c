#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: name of file to be appended
 * @text_content: text to be appended to the end of the file
 *
 * Return: 1 (success), -1 for failure
 */
int append_text_to_file(const char *filename, char *text_content)

{
	int a, b, c;

	a = b = c = 0;
	if (!filename)
		return (-1);
	else if (!text_content || !text_content[0])
		return (1);
	a = open(filename, O_WRONLY | O_APPEND);
	if (a < 0)
		return (-1);
	while (text_content[c])
		c++;
	b = write(b, text_content, c);
	if (b < 0)
		return (-1);
	close(a);
	return (1);
}
