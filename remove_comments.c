#include "shell.h"

/**
 *remove_comments - removes comments from a string.
 *@ptr: arg 1.
 *@global: arg 2.
 *Return: string.
 */
char *remove_comments(char *ptr, global_t *global)
{
	int len = 0, i = 0;
	char    *str;

	if (!ptr)
	{
		free_all(global);
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
