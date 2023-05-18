#include "shell.h"

/**
 *str_copy1 - Copy substring from str until character a
 *
 *@str: The source string
 *@index: Pointer to the current index in the string
 *@a: The character to search for
 *
 *
 *Description: Copies the substring from 
 *the source string starting from the
 *current index until the character  a
 *The currentindex is updated to the next 
 *position after the copied substring
 *
 *
 */

static char	*str_copy1(char	*str, int *index, char a)
{
	int		i;
	int		start;
	char	*ptr;
	int		y;

	i = 0;
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
 *init_env - Initialize the environment variables
 *
 *@envp: Array of environment strings
 *
 * Description: Parses the environment strings
 * creates a linked list of environment variables
 * Sets global variables for the shell
 * 
 */
void	init_env(char **envp, global_t *global)
{
	int		i;
	env_t	*env;
	env_t	*head;
	int		index;

	i = 0;
	head = NULL;
	while (envp[i])
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
}







/**
 *env_search - Search for an environment variable
 *
 * @str: Name of the environment variable to search for
 *
 *
 *Return: Value of the environment variable if found, or NULL
 *
 *
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
