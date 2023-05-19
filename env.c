#include "shell.h"
/**
 * env - prints the environment.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void env(char **cmd, global_t *global)
{
	env_t *ptr = global->env;

	(void)cmd;
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
