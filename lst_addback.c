#include "shell.h"

/**
 *lstadd_back_env - Add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_env(env_t **lst, env_t *new)
{
	env_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}

/**
 *lstadd_back_command - Add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_command(command_t **lst, command_t *new)
{
	command_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}

/**
 *lstadd_back_alias - Add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_alias(alias_t **lst, alias_t *new)
{
	alias_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}
