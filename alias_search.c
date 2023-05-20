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
 * aliassearch - search for an alias.
 * @str: arg 1.
 * @global: arg 2.
 * Return: alias_t or NULL.
 */
alias_t	*aliassearch(char	*str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
