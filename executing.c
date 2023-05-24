#include "shell.h"

/**
 *exec_binary - Execute binary fils.
 *@command: arg 1.
 *@global: arg 2.
 */
void	exec_binary(command_t *command, global_t *global)
{
	pid_t	n;
	int		m;

	if (!command->path)
	{
		print_error(command->args[0], "not found", global);
		global->exit_code = 127;
	}
	else if (access(command->path, X_OK))
	{
		print_error(command->args[0], "Permission denied", global);
		global->exit_code = 126;
	}
	else
	{
		n = fork();
		if (!n)
			execve(command->path, command->args, global->envp);
		else
		{
			waitpid(n, &m, 0);
			if (WIFEXITED(m))
				global->exit_code = WEXITSTATUS(m);
		}
	}
}

/**
 *executing - Execute commands.
 *@global: arg 1.
 */
void	executing(global_t *global)
{
	command_t	*tmp = global->commands;
	char		**str;
	id_t		i = 0;

	while (tmp)
	{
		if (tmp->args)
		{
			if (!exec_builtin(tmp->args, global))
				exec_binary(tmp, global);
		}
		else if (tmp->tmp)
		{
			str = advanced_split(tmp->tmp, global);
			exec_logical_operators(str, global);
			while (str && str[i])
				free(str[i++]);
			free(str);
		}
		tmp = tmp->next;
	}
}
