#include "shell.h"

/**
 *help_va_re - variables replacement.
 *@ptr: arg 1.
 *@global: arg 2.
 *Return: pointer to  modified string
 */
char *help_va_re(char *ptr, global_t *global)
{
	int	i = 0;
	char **str = split(ptr, ' '), *str2 = NULL, *tmp;

	while (str[i])
	{
		if (str[i][0] == '$' && str[i][1])
		{
			tmp = str[i];
			if (env_search(str[i] + 1, global))
				str[i] = _strdup(env_search(str[i] + 1, global));
			else
				str[i] = _strdup("");
			free(tmp);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		str2 = _strjoin(str2, str[i]);
		str2 = _strjoin(str2, " ");
		i++;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(ptr);
	return (str2);
}

/**
 *va_re - variables replacement.
 *@ptr: arg 1.
 *@global: arg 2.
 *Return: pointer to  modified string
 */
char	*va_re(char *ptr, global_t *global)
{
	char	*str = NULL, *tmp;
	int		i = 0, m = 0;

	if (!ptr)
		return (NULL);
	while (ptr[i])
	{
		if (!_strncmp(ptr + i, "$$", 2) || !_strncmp(ptr + i, "$?", 2))
		{
			if (!_strncmp(ptr + i, "$$", 2))
				tmp = _itoa(global->pid);
			else if (!_strncmp(ptr + i, "$?", 2))
				tmp = _itoa(global->exit_code);
			ptr[i] = 0;
			str = _strjoin(str, ptr + m);
			str = _strjoin(str, tmp);
			free(tmp);
			ptr[i] = '$';
			i++;
			m = i + 1;
		}
		if (ptr[i])
			i++;
	}
	if (!str)
		str = _strdup(ptr);
	free(ptr);
	return (help_va_re(str, global));
}
