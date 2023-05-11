/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:15:28 by ramhouch          #+#    #+#             */
/*   Updated: 2023/05/11 15:47:24 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*str_copy1(char	*str, int *index, char a)
{
	int		i;
	int		start;
	char	*ptr;
	int		y;

	i = 0;
	start = *index;
	while (str[i] && str[i] != a)
	{
		i++;
		*index = *index + 1;
	}
	ptr = malloc(i + 1);
	y = 0;
	while (y < i)
		ptr[y++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

void	init_env(char **envp)
{
	int		i;
	env_t	*env;
	env_t	*head;
	int		index;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		index = 0;
		env = malloc(sizeof(env_t));
		env->name = str_copy1(envp[i], &index, '=');
		index++;
		env->value = str_copy1(envp[i], &index, 0);
		env->next = NULL;
		lstadd_back_env(&head, env);
		i++;
	}
	global.env = head;
	global.exit_code = 0;
	global.pid = getpid();
	global.alias = NULL;
}

char	*env_search(char	*str)
{
	env_t	*ptr;

	ptr = global.env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}
