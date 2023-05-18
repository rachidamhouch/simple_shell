#include "shell.h"

char	*va_re(char *ptr, global_t *global)
{
	char	*str = NULL, *tmp;
	int		i = 0, m = 0;

	if (!ptr)
		return (NULL);
	while(ptr[i])
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
	return (str);
}
