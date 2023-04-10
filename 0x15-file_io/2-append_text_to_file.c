#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to write into
 * @text_content: string to append to the end of the file
 *
 * Return: 1 on success, -1 if it fails
 */
int append_text_to_file(const char *filename, char *text_content)

{
	int w, err, len;

	w = err = len = 0;
	if (!filename)
		return (-1);
	else if (!text_content || !text_content[0])
		return (1);
	w = open(filename, O_WRONLY | O_APPEND);
	if (w < 0)
		return (-1);
	while (text_content[len])
		len++;
	err = write(w, text_content, len);
	if (err < 0)
		return (-1);
	close(w);
	return (1);
}
