#include "shell.h"

/**
 *help_cd - help cd function.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void help_cd(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;

	if (!env_search("OLDPWD", global))
		print_error(cmd[0], env_search("PWD", global), global);
	else
	{
		tmp = getcwd(0, 0);
		if (chdir(env_search("OLDPWD", global)))
		{
			perror("cd");
			free(tmp);
		}
		else
		{
			t[2] = env_search("OLDPWD", global);
			print(t[2], 1, 1);
			_setenv(t, global);
			t[1] = "OLDPWD";
			t[2] = tmp;
			_setenv(t, global);
			free(tmp);
		}
	}
}

/**
 *help_cd2 - help cd function.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void help_cd2(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;

	tmp = getcwd(0, 0);
	if (chdir(cmd[1]))
	{
		perror("cd");
		free(tmp);
	}
	else
	{
		t[2] = getcwd(0, 0);
		_setenv(t, global);
		free(t[2]);
		t[1] = "OLDPWD";
		t[2] = tmp;
		_setenv(t, global);
		free(tmp);
	}
}

/**
 *cd - change the current directory.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void cd(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;
	if (!cmd[1])
	{
		if (env_search("HOME", global))
		{
			tmp = getcwd(0, 0);
			if (chdir(env_search("HOME", global)))
			{
				perror("cd");
				free(tmp);
			}
			else
			{
				t[2] = env_search("HOME", global);
				_setenv(t, global);
				t[1] = "OLDPWD";
				t[2] = tmp;
				_setenv(t, global);
				free(tmp);
			}
		}
	}
	else
	{
		if (cmd[1][0] == '-' && !cmd[1][1])
			help_cd(cmd, global);
		else
			help_cd2(cmd, global);
	}
}
