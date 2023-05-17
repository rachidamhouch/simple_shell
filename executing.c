#include "shell.h"

/**
 *exec_binary - Execute binary command
 *@command: Pointer to the command structure
 *
 *Description: Executes the binary command specified
 *
 *
 */

void	exec_binary(command_t *command)
{
	pid_t	n;
	int		m;

	if (!command->path)
	{
		print_error(command->args[0], "command not found");
		global.exit_code = 127;
	}
	else if(access(command->path, X_OK))
	{
		print_error(command->args[0], "Permission denied");
		global.exit_code = 126;
	}
	else
	{
		n = fork();
		if (!n)
			execve(command->path, command->args, global.envp);
		else
		{
			waitpid(n, &m, 0);
			if (WIFEXITED(m) )
        		global.exit_code = WEXITSTATUS(m);
		}
	}
}





/**
 *executing - Execute commands
 *
 *Description: Executes the commands stored
 *
 *
 *
 */

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
