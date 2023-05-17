#include "shell.h"
/**
 *free_commands - Free the memory allocated for command structures
 *
 */
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






/**
 *get_path - Get the full path of a command
 *
 *@str: The command name
 *
 *
 *Return: The full path of the command, or NULL if not found
 *
 */
char	*get_path(char *str)
{
	char	*ptr = _strdup(str), **paths, *tmp;
	int		i = 0;

	if (!access(ptr, F_OK))
		return (ptr);
	paths = split(env_search("PATH"), ':');
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
 *get_paths - Get the full paths of commands in the command list
 *
 *
 */
void	get_paths(void)
{
	command_t	*tmp = global.commands;

	while (tmp)
	{
		tmp->path = get_path(tmp->args[0]);
		tmp = tmp->next;
	}
}




/**
 *
 *
 *get_commands - Parse and store the commands from a string
 *
 *@ptr: The input string containing commands
 */
void	get_commands(char *ptr)
{
	char	    **commands;
	int         i = 0;
	command_t   *node;

	free_commands();
	if (!ptr)
		return;
	commands = split(ptr, ';');
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
	get_paths();
}
