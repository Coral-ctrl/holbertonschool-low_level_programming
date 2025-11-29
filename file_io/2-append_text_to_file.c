#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	/* Open file in O_WRONLY | O_APPEND (do not create if missing) */
	fd = open(filename, O_WRONLY | O_APPEND);
	/* If text_content is NULL, don't write, just return 1 */
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	} else
	{
		close(fd);
		return (1);
	}

	if (fd == -1)
		return (-1);

	/* Write to file */
	w = write(fd, text_content, len);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
