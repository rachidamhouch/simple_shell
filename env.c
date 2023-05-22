#include "shell.h"
/**
 * env - prints the environment.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void env(char **cmd, global_t *global)
{
	env_t *ptr = global->env;

	if (cmd[1])
	{
		print("env: ‘", 2, 0);
		print(cmd[1], 2, 0);
		print("’: No such file or directory", 2, 1);
		global->exit_code = 127;
		return;
	}
	while (ptr)
	{
		if (ptr->name)
		{
			print(ptr->name, 1, 0);
			print("=", 1, 0);
			print(ptr->value, 1, 1);
		}
		ptr = ptr->next;
	}
	global->exit_code = 0;
}
