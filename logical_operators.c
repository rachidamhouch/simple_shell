#include "shell.h"

/**
 *is_lo_op - con || or &&.
 *@str: arg 1.
 *Return: 0 or 1.
 */
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

/**
 *count_words - count number of words.
 *@str: arg 1.
 *@global: arg 2.
 *Return: number of words.
 */
int	count_words(char *str, global_t *global)
{
	int	count = 0, c = 1, i = 0;

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
		if ((str[i] == '|' && str[i + 1] && str[i + 1] == '|') ||
			(str[i] == '&' && str[i + 1] && str[i + 1] == '&'))
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

/**
 *copy_str - dup an new word.
 *@str: arg 1.
 *@index: arg 2.
 *Return: new word.
 */
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

/**
 *advanced_split - split words.
 *@str: arg 1.
 *@global: arg 2.
 *Return: array of strings.
 */
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

/**
 *exec_logical_operators - exec_logical_operators.
 *@str: arg 1.
 *@global: arg 2.
 */
void exec_logical_operators(char **str, global_t *global)
{
	int		i = 0;
	char	n = 0, m, v = 1;
	command_t	*node = malloc(sizeof(command_t));

	while (str[i])
	{
		str = str + i;
		i = 0;
		while (1)
		{
			if (!str[i] || !_strncmp(str[i], "||", 3) || !_strncmp(str[i], "&&", 3))
			{
				if (str[i] && !_strncmp(str[i], "&&", 3))
					m = '&';
				else if (str[i] && !_strncmp(str[i], "||", 3))
					m = '|';
				if (!str[i])
					v = 0;
				free(str[i]);
				str[i] = NULL;
				node->path = get_path(str[0], global);
				node->args = str;
				if (!n || (n == '|' && global->exit_code) ||
					(n == '&' && !global->exit_code))
				{
					if (!exec_builtin(node->args, global))
						exec_binary(node, global);
				}
				free(node->path);
				n = m;
				if (v)
					str[i++] = _strdup("anything");
				break;
			}
			i++;
		}
	}
	free(node);
}
