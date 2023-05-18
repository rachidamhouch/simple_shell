#include "shell.h"
/**
 * env - prints the environment.
 * @cmd: arg 1.
 */
void env(char **cmd)
{
	(void)cmd;
	char **env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

}
