#include "shell.h"

void handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}

int main(int ac, char **av, char **env)
{
	char	*ptr, fd = 0;

	signal(SIGINT, handler);
	if (ac > 1)
	{
		fd = open(av[1], O_WRONLY);
		if (fd == -1)
		{
			write(2, av[0], _strlen(av[0]));
			write(2, ": Can't open ", _strlen(": Can't open "));
			write(2, av[1], _strlen(av[1]));
			write(2, "\n", 1);
			return (1);
		}
	}
	init_env(env);
	while (1)
	{
		write(1, "$ ", 2);
		ptr = va_re(alias(remove_comments(get_next_line(fd))));
		write(1, ptr, _strlen(ptr));
		write(1, "\n", 1);
		free(ptr);
	}
	return (0);
}

