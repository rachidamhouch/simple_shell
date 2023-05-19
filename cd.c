#include "shell.h"

/**
 *cd - change thr current directory.
 *@cmd: arg 1.
 */
void cd(char **cmd)
{
	(void)cmd;
	if (cmd[1] == NULL)
	{
		const char *home_dir = getenv("HOME");
		if (home_dir == NULL) 
		{
			write(STDERR_FILENO, "cd: no HOME envirronment variable set\n", 36);
			return;
		}
		if (chdir(home_dir) != 0)
		{
			peroor("cd");
		}
	else if (strcpm(cmd[1], "-") == 0)
	{

	}
	}
}
