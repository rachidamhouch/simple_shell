#include "shell.h"

/**
 *_setenv - set var env.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void _setenv(char **cmd, global_t *global)
{
	int		i = 0;
	env_t	*tmp;

	(void)global;
	while (cmd[i])
		i++;
	if (i != 3)
	{
		print("Incorrect number of arguements", 2, 1);
		global->exit_code = 127;
	}
	else
	{
		global->exit_code = 0;
		tmp = envsearch(cmd[1], global);
		if (tmp)
		{
			free(tmp->value);
			tmp->value = _strdup(cmd[2]);
		}
		else
		{
			tmp = malloc(sizeof(env_t));
			tmp->next = NULL;
			tmp->name = _strdup(cmd[1]);
			tmp->value = _strdup(cmd[2]);
			lstadd_back_env(&global->env, tmp);
		}
	}
}

/**
 *_unsetenv - unset var env.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void _unsetenv(char **cmd, global_t *global)
{
	env_t	*tmp;
	int		i = 1;

	if (!cmd[1])
	{
		print("Too few arguements", 2, 1);
		global->exit_code = 127;
	}
	else
	{
		while (cmd[i])
		{
			tmp = envsearch(cmd[i], global);
			if (tmp)
			{
				free(tmp->name);
				free(tmp->value);
				tmp->name = NULL;
				tmp->value = NULL;
				global->exit_code = 0;
			}
			else
				global->exit_code = 127;
			i++;
		}
	}
}
