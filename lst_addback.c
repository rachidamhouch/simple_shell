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
