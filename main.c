#include "shell.h"
/**
 *handler - signal handler for Ctrl+C=SIGINT.
 *@sig: arg 1.
 */
void handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}

/**
 *main - main function.
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
		ptr = va_re(alias(remove_comments(_getline(fd), global), global), global);
		global->cmd = ptr;
		get_commands(ptr, global);
		executing(global);
		free(ptr);
	}
	free_all(global);
	return (0);
}

