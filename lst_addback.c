/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:15:38 by ramhouch          #+#    #+#             */
/*   Updated: 2023/05/10 21:44:05 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 *lstadd_back_env - Add a new element to the end of an environment list
 *
 *@lst: Pointer to the head of the environment list
 *@new: New element to be added
 *
 */
void	lstadd_back_env(env_t **lst, env_t *new)
{
	env_t	*item;

	if (!lst || !new)
		return ;
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
 *lstadd_back_command - Add a new element to the end of a command list
 *
 *@lst: Pointer to the head of the command list
 *
 *@new: New element to be added
 */
void	lstadd_back_command(command_t **lst, command_t *new)
{
	command_t	*item;

	if (!lst || !new)
		return ;
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
 *lstadd_back_alias - Add a new element to the end of an alias list
 *
 *@lst: Pointer to the head of the alias list
 *
 *@new: New element to be added
 *
 */
void	lstadd_back_alias(alias_t **lst, alias_t *new)
{
	alias_t	*item;

	if (!lst || !new)
		return ;
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
