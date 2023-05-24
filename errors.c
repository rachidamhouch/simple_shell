#include "shell.h"
/**
 * print_error - Print error message.
 * @cmd: arg 1.
 * @msg: arg 2.
 * @global: arg 3.
 * Return: 1
 */
int	print_error(char *cmd, char *msg, global_t *global)
{
	write(2, global->name, _strlen(global->name));
	write(2, ": ", 2);
	putnbr_fd(global->n, 2);
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, _strlen(msg));
	write(2, "\n", 1);
	return (1);
}

/**
 * print - Print message.
 * @str: arg 1.
 * @fd: arg 2.
 * @new: arg 3.
 * Return: the length.
 */
int print(char *str, int fd, int new)
{
	write(fd, str, _strlen(str));
	if (new)
		return (write(fd, "\n", 1));
	return (1);
}
