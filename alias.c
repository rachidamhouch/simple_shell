#include "shell.h"
/**
 * alias_search - search for an alias.
 * @str: arg 1.
 * @global: arg 2.
 * Return: string or NULL.
 */
char	*alias_search(char	*str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 * alias - Implements the alias built-in.
 * @ptr: arg 1.
 * @global: arg 2.
 * Return: string or NULL.
 */
char	*alias(char *ptr, global_t *global)
{
	int	i = 0;
	char **str = split(ptr, ' '), *str2 = NULL;

	while (str[i])
	{
		if (alias_search(str[i], global))
		{
			free(str[i]);
			str[i] = _strdup(alias_search(str[i], global));
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		str2 = _strjoin(str2, str[i]);
		str2 = _strjoin(str2, " ");
		i++;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(ptr);
	return (str2);
}
