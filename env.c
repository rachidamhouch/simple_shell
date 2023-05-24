#include "shell.h"
/**
 * env - prints the environment.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void env(char **cmd, global_t *global)
{
	int i;

	(void)cmd;
	(void)global;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
	global->exit_code = 0;
}
