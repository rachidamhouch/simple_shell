#include "shell.h"

/**
 *get_path - Get the path of  command.
 *@str: arg 1.
 *@global: arg 2.
 *Return: The Path of a command.
 */
char	*get_path(char *str, global_t *global)
{
	char	*ptr = _strdup(str), **paths, *tmp;
	int		i = 0;

	if (!access(ptr, F_OK))
		return (ptr);
	paths = split(env_search("PATH", global), ':');
	while (paths[i])
	{
		tmp = _strjoin(_strdup(paths[i]), "/");
		tmp = _strjoin(tmp, ptr);
		if (!access(tmp, F_OK))
		{
			i = 0;
			while (paths[i])
				free(paths[i++]);
			free(paths);
			free(ptr);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(ptr);
	return (NULL);
}

/**
 *get_paths - Get the full paths of commands.
 *@global: arg 2.
 */
void	get_paths(global_t *global)
{
	command_t	*tmp = global->commands;

	while (tmp)
	{
		tmp->path = get_path(tmp->args[0], global);
		tmp = tmp->next;
	}
}

/**
 *get_commands - parse and store the commands.
 *@ptr: arg 1.
 *@global: arg 2.
 */
void	get_commands(char *ptr, global_t *global)
{
	char	    **commands;
	int         i = 0;
	command_t   *node;

	free_commands(global);
	if (!ptr)
		return;
	commands = split(ptr, ';');
	while (commands[i])
	{
		commands[i] = va_re(alias(commands[i], global), global);
		node = malloc(sizeof(command_t));
		node->path = NULL;
		node->next = NULL;
		node->args = split(commands[i], ' ');
		lstadd_back_command(&global->commands, node);
		i++;
	}
	i = 0;
	while (commands[i])
		free(commands[i++]);
	free(commands);
	get_paths(global);
}
