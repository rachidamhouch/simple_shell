#include "shell.h"

/**
 *remove_comments - removes comments from a string.
 *@ptr: arg 1.
 *@global: arg 2.
 *@fd: arg 3.
 *Return: string.
 */
char *remove_comments(char *ptr, global_t *global, int fd)
{
	int len = 0, i = 0, n;
	char    *str;

	if (!ptr)
	{
		global->cmd = NULL;
		if (isatty(fd))
			write(1, "\n", 1);
		n = global->exit_code;
		free_all(global);
		exit(n);
	}
	while (ptr[len] && ptr[len] != '\n')
	{
		if (ptr[len] == '#')
			if (ptr + len == ptr || ptr[len - 1] == ' ' || ptr[len - 1] == '\t')
				break;
		len++;
	}
	str = malloc(len + 1);
	while (ptr[i] && ptr[i] != '\n')
	{
		if (ptr[i] == '#')
			if (ptr + i == ptr || ptr[i - 1] == ' ' || ptr[i - 1] == '\t')
				break;
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	free(ptr);
	return (str);
}
