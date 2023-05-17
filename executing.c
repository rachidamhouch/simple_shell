#include "shell.h"

void	exec_binary(command_t *command)
{
	if (!command->path)
		print_error(command->args[0], "command not found");
	else if(!access("command->path", X_OK))
		print_error(command->args[0], "Permission denied");
}

void	executing(void)
{
	command_t *tmp = global.commands;

	while (tmp)
	{
		if (!exec_builtin(tmp->args))
			exec_binary(tmp);
		tmp = tmp->next;
	}
}
