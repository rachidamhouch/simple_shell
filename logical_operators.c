#include "shell.h"

int	is_lo_op(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '&' && str[i + 1] == '&')
			return (1);
		if (str[i] == '|' && str[i + 1] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, global_t *global)
{
	int	count = 0, c = 1, i =0;
	if (str[0] == '|' && str[1] && str[1] == '|')
	{
		print(global->name, 2, 0);
		print(": ", 2, 0);
		putnbr_fd(global->n, 2);
		print(": Syntax error: \"||\" unexpected", 2, 1);
		return (count);
	}
	if (str[0] == '&' && str[1] && str[1] == '&')
	{
		print(global->name, 2, 0);
		print(": ", 2, 0);
		putnbr_fd(global->n, 2);
		print(": Syntax error: \"&&\" unexpected", 2, 1);
		return (count);
	}
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			c = 1;
		if ((str[i] == '|' && str [i + 1] && str [i + 1] == '|') ||
			(str[i] == '&' && str [i + 1] && str [i + 1] == '&'))
		{
			c = 1;
			count++;
			i += 2;
		}
		if (c && str[i] != ' ' && str[i] != '\t')
		{
			count++;
			c = 0;
		}
		i++;
	}
	return (count);
}

char *copy_str(char *str, int *index)
{
	int		i = *index, start, len = 0;
	char	*ptr;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '|' && str[i + 1] && str[i + 1] == '|')
	{
		*index = i + 2;
		return (_strdup("||"));
	}
	if (str[i] == '&' && str[i + 1] && str[i + 1] == '&')
	{
		*index = i + 2;
		return (_strdup("&&"));
	}
	start = i;
	while (str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] == '|' && str[i + 1] && str[i + 1] == '|')
			break;
		if (str[i] == '&' && str[i + 1] && str[i + 1] == '&')
			break;
		i++;
		len++;
	}
	*index = i;
	ptr = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[start];
		i++;
		start++;
	}
	ptr[len] = '\0';
	return (ptr);
}


char **advanced_split(char *str, global_t *global)
{
	int		count = count_words(str, global), i = 0, index = 0;
	char	**ptr;

	if (!count)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		ptr[i] = copy_str(str, &index);
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

