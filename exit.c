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
	unsigned char n;

	if (!cmd[1])
	{
		free_all(global);
		print("exit", 1, 1);
		exit(0);
	}
	else
	{
		if (cmd[0] && cmd[1] && cmd[2] && is_num(cmd[1]))
		{
			print("exit", 2, 1);
			print_error(cmd[0], "too many arguments", global);
			global->exit_code = 1;
		}
		else
		{
			if (is_num(cmd[1]))
			{
				n = _atoi(cmd[1]);
				print("exit", 1, 1);
				free_all(global);
				exit(n);
			}
			else
			{
				print("exit", 2, 1);
				print(global->name, 2, 0);
				print(": exit: ", 2, 0);
				print(cmd[1], 2, 0);
				print(": numeric argument required", 2, 1);
				free_all(global);
				exit(2);
			}
		}
	}
}
