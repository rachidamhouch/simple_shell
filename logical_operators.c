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
		if (str[i] == '|' && str [i + 1] && str [i + 1] == '|')
		{
			c = 1;
			count++;
			i += 2;
		}
		if (str[i] == '&' && str [i + 1] && str [i + 1] == '&')
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

char **advanced_split(char *str, global_t *global)
{
	int	count = count_words(str, global);

	if (!count)
		return (NULL);
	printf("%d\n", count);
	return (NULL);
}

