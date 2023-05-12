#include "shell.h"

void    free_commands(void)
{
	command_t	*tmp = global.commands, *tmp2;
	char		**str;
	int			i;

	while (tmp)
	{
		i = 0;
		tmp2 = tmp->next;
		free(tmp->path);
		str = tmp->args;
		while (str[i])
			free(str[i++]);
		free(str);
		free(tmp);
		tmp = tmp2;
	}
	global.commands = NULL;
}

void	get_commands(char *ptr)
{
	char	    **commands = split(ptr, ';');
	int         i = 0;
	command_t   *node;

	free_commands();
	while (commands[i])
	{
		node = malloc(sizeof(command_t));
		node->path = NULL;
		node->next = NULL;
		node->args = split(commands[i], ' ');
		lstadd_back_command(&global.commands, node);
		i++;
	}
	i = 0;
	while (commands[i])
		free(commands[i++]);
	free(commands);
}
