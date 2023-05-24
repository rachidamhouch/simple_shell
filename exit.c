#include "shell.h"

/**
 * is_num - is number.
 * @str: arg 1.
 * Return: 1 if is number.
 */
int	is_num(char *str)
{
	int i = 0;

	if (str[0] && (str[0] == '-' || str[0] == '+'))
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] == '0')
	{
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * my_exit - exit the shell.
 * @cmd: arg 1;
 * @global: arg 2.
 */
void    my_exit(char **cmd, global_t *global)
{
	int n;

	if (!cmd[1])
	{
		n = global->exit_code;
		free_all(global);
		exit(n);
	}
	else
	{
		if (!is_num(cmd[1]) || _atoi(cmd[1]) < 0)
		{
			print(global->name, 2, 0);
			print(": ", 2, 0);
			putnbr_fd(global->n, 2);
			print(": exit: Illegal number: ", 2, 0);
			print(cmd[1], 2, 1);
			global->exit_code = 2;
		}
		else
		{
			n = _atoi(cmd[1]);
			free_all(global);
			exit((unsigned char)n);
		}
	}
}
