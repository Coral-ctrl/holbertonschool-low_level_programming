#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * close_fd - closes a file descriptor and handles error
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_file_from - opens the source file for reading
 * @filename: name of the source file
 *
 * Return: file descriptor of the opened file
 * Description: Exits with code 98 if the file cannot be opened.
 */
int open_file_from(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * open_file_to - opens/creates the destination file for writing
 * @filename: name of the destination file
 *
 * Return: file descriptor of the opened/created file
 * Description: Exits with code 99 if the file cannot be opened or created.
 */
int open_file_to(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}

/**
 * copy_file - copies content from one file descriptor to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 *
 * Description: Reads up to 1024 bytes at a time from fd_from
 *              and writes to fd_to.
 * Exits with code 98 if read fails, 99 if write fails.
 */
void copy_file(int fd_from, int fd_to)
{
	char buffer[1024];
	ssize_t r, w;

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

/**
 * main - copies content from one file to another
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);

	fd_to = open_file_to(argv[2]);

	copy_file(fd_from, fd_to);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
