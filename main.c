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
	global.name = av[0];
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (print_error(av[1], "Can't open it"));
	}
	init_env(env);
	while (1)
	{
		if (!fd)
			write(1, "$ ", 2);
		ptr = va_re(alias(remove_comments(get_next_line(fd), fd)));
		get_commands(ptr);
		executing();
		free(ptr);
	}
	return (0);
}

