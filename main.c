#include "shell.h"
/**
 *handler - Signal handler for SIGINT
 *@sig: arg 1.
 */
void handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}

/**
 *main - Entry point of the program
 *@ac: The number of arguments
 *@av: Array of argument strings
 *@env: Array of environment string
 * Return: 0 always
 */
int main(int ac, char **av, char **env)
{
	char		*ptr, fd = 0;
	global_t	*global;

	signal(SIGINT, handler);
	global = malloc(sizeof(global_t));
	global->name = av[0];
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (print_error(av[1], "Can't open it", global));
	}
	init_env(env, global);
	while (1)
	{
		if (!fd)
			write(1, "$ ", 2);
		ptr = va_re(alias(remove_comments(get_next_line(fd), fd), global), global);
		get_commands(ptr, global);
		executing(global);
		free(ptr);
	}
	return (0);
}

