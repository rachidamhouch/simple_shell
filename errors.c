#include "shell.h"
/**
 * print_error - Print error message to stderr
 * @cmd: The command name
 * @msg: The error message
 *
 * Return: 1
 */
int	print_error(char *cmd, char *msg, global_t *global)
{
	write(2, global->name, _strlen(global->name));
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, _strlen(msg));
	write(2, "\n", 1);
	return (1);
}
