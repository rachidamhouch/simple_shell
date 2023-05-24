#include "shell.h"

/**
 *str_copy1 - Copy substring from str.
 *@str: arg 1.
 *@index: arg 2.
 *@a: arg 3.
 *Return: String.
 */
char	*str_copy1(char	*str, int *index, char a)
{
	int		i;
	int		start;
	char	*ptr;
	int		y;

	i = *index;
	start = *index;
	while (str[i] && str[i] != a)
	{
		i++;
		*index = *index + 1;
	}
	ptr = malloc(i + 1);
	y = 0;
	while (y < i)
		ptr[y++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

/**
 *init_env - Initialize the environment variables.
 *@envp: arg 1.
 *@global: arg 2.
 */
void	init_env(char **envp, global_t *global)
{
	int		i;
	env_t	*env;
	env_t	*head;
	int		index;

	i = 0;
	head = NULL;
	while (envp && envp[i])
	{
		index = 0;
		env = malloc(sizeof(env_t));
		env->name = str_copy1(envp[i], &index, '=');
		index++;
		env->value = str_copy1(envp[i], &index, 0);
		env->next = NULL;
		lstadd_back_env(&head, env);
		i++;
	}
	global->env = head;
	global->commands = NULL;
	global->exit_code = 0;
	global->pid = getpid();
	global->alias = NULL;
	global->envp = envp;
	global->n = 1;
}

/**
 *env_search - Search for an environment variable.
 * @str: arg 1.
 * @global: arg 2.
 *Return: Value of the env if found, or NULL
 */
char	*env_search(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 *envsearch - Search for an environment variable.
 * @str: arg 1.
 * @global: arg 2.
 *Return: Value of the env if found, or NULL
 */
env_t	*envsearch(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
