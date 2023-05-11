#include "shell.h"

int main(int ac, char **av, char **env)
{
	char	*ptr, fd = 0;

	if (ac > 1)
	{
		fd = open(av[1], O_WRONLY);
		if (fd == -1)
		{
			write(2, av[0], _strlen(av[0]));
			write(2, ": 0: Can't open ", _strlen(": 0: Can't open "));
			write(2, av[1], _strlen(av[1]));
			write(2, "\n", 1);
			return (1);
		}
	}
	init_env(env);
	while (1)
	{
		write(1, "$ ", 2);
		ptr = alias(remove_comments(get_next_line(fd)));
		free(ptr);
	}
	return (0);
}

