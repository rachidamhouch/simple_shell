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
int	is_new(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
/**
 * aliassprint - search for an alias.
 * @str: arg 1.
 * @global: arg 2.
 * Return: string or NULL.
 */
char	*aliassprint(char	*str, global_t *global)
{
	if (alias_search(str, global))
	{
		print(str, 1, 0);
		print("='", 1, 0);
		print(alias_search(str, global), 1, 0);
		print("'", 1, 1);
	}
	return (0);
}

void _alias(char **cmd, global_t *global)
{
	alias_t *ptr = global->alias, *node;
	int	i = 1, index;

	if (!cmd[1])
	{
		while (ptr)
		{
			print(ptr->name, 1, 0);
			print("='", 1, 0);
			print(ptr->value, 1, 0);
			print("'", 1, 1);
			ptr = ptr->next;
		}
	}
	else
	{
		while (cmd[i])
		{
			if (!alias_search(cmd[i], global) && !is_new(cmd[i]))
			{
				print("alias: ", 2, 0);
				print(cmd[i], 2, 0);
				print(" not found", 2, 1);
			}
			i++;
		}
		i = 1;
		while (cmd[i])
		{
			if (is_new(cmd[i]))
			{
				index = 0;
				node = malloc(sizeof(alias_t));
				node->next = NULL;
				node->name = str_copy1(cmd[i], &index, '=');
				index++;
				node->value = str_copy1(cmd[i], &index, 0);
				lstadd_back_alias(&global->alias, node);
			}
			else
				aliassprint(cmd[i], global);
			i++;
		}
	}
}
