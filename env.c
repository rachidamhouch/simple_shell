#include "shell.h"
/**
 * env - prints the environment.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void env(char **cmd, global_t *global)
{
	int	i = 0;
	char **str = global->envp;

	(void)cmd;
	while (str[i])
	{
		print(str[i], 1, 1);
		i++;
	}
	global->exit_code = 0;
}
