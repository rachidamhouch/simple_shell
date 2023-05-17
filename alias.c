#include "shell.h"
/**
 * alias_search - Implements the "alias" builtin command
 * @str: Pointer to  struct with the shell state and args.
 *
 * This function defines new aliases in the shell
 * prints all existing aliases in the shell
 */
char	*alias_search(char	*str)
{
	alias_t	*ptr;

	ptr = global.alias;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

char	*alias(char *ptr)
{
	int	i = 0;
	char **str = split(ptr, ' '), *str2 = NULL;

	while (str[i])
	{
		if (alias_search(str[i]))
		{
			free(str[i]);
			str[i] = _strdup(alias_search(str[i]));
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
