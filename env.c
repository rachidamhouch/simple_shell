#include "shell.h"

void env(char **cmd)
{
	char **cmd = environ;
	while (*cmd != NULL)
	{
        printf("%s\n", *cmd);
        cmd++;
	}
}
