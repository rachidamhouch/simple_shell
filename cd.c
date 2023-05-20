#include "shell.h"

/**
 *cd - change the current directory.
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
			write(STDERR_FILENO, "cd: no HOME envirronments variables set\n", 38
			);
			return;
		}
		if (chdir(home_dir) != 0)
		{
			peroor("cd");
		}
	else if (strcpm(cmd[1], "-") == 0)
	{
		const char *old_dir = getenv("OLDPWD");
		if (old_dir == NULL)
		{
			 write(STDERR_FILENO, "cd: No OLDPWD environments variables set\n", 40);
			 return;
		}
		if (chdir(home_dir) !=0)
		{
			perror("cd");
		}
	}
}
