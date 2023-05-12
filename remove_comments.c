#include "shell.h"

char *remove_comments(char *ptr, int fd)
{
	int len = 0, i = 0;
	char    *str;

	if (!ptr)
	{
		if (!fd)
			write(1, "exit\n", 5);
		exit(0);
	}
	while (ptr[len] && ptr[len] != '#' && ptr[len] != '\n')
		len++;
	str = malloc(len + 1);
	while (ptr[i] && ptr[i] != '#' && ptr[i] != '\n')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	free(ptr);
	return (str);
}
