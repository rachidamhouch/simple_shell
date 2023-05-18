#ifndef SHELL_H
# define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/**
 * struct command_s - singly linked list
 * @path: the path.
 * @args: the args.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for command.
 */
typedef struct command_s
{
	char		        *path;
	char		        **args;
	struct command_s	*next;
} command_t;

/**
 * struct alias_s - singly linked list
 * @name: the nmae.
 * @value: the value.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure
 * for alias.
 */
typedef struct alias_s
{
	char		    *name;
	char		    *value;
	struct alias_s	*next;
} alias_t;

/**
 * struct env_s - singly linked list
 * @name: the name.
 * @value: the value.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for env.
 */
typedef struct env_s
{
	char		    *name;
	char		    *value;
	struct env_s	*next;
} env_t;

/**
 * struct global_s - global variable.
 * @commands: the commands.
 * @env: the env.
 * @alias: the alias.
 * @exit_code: the exit code.
 * @pid: the pid.
 * @name: the name.
 * @envp: the envp.
 *
 * Description: global variable.
 */
typedef struct global_s
{
	command_t   *commands;
	env_t       *env;
	alias_t     *alias;
	int		    exit_code;
	pid_t       pid;
	char        *name;
	char        **envp;
} global_t;

# define BUFFER_SIZE 1024
char	*_getline(int fd);
size_t	my_strlen(const char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *s, int c);
void	*my_memcpy(void *dst, const void *src, size_t n);
char	*remove_comments(char *ptr, global_t *global);
void	lstadd_back_env(env_t **lst, env_t *new);
void	init_env(char **envp, global_t *global);
char	*env_search(char	*str, global_t *global);
size_t	_strlen(const char *s);
int     _strncmp(const char *s1, const char *s2, size_t n);
void	lstadd_back_command(command_t **lst, command_t *new);
void	lstadd_back_alias(alias_t **lst, alias_t *new);
char	**split(char const *s, char c);
char	*_strdup(const char *s1);
char	*alias(char *ptr, global_t *global);
char	*_strjoin(char *s1, char *s2);
char	*_itoa(int n);
char    *va_re(char *ptr, global_t *global);
void	get_commands(char *ptr, global_t *global);
int     exec_builtin(char **args);
void	executing(global_t *global);
int     print_error(char *cmd, char *msg, global_t *global);
void    env(char **cmd);
void    cd(char **cmd);
void    my_exit(char **cmd);
void	free_all(global_t *global);
void	free_commands(global_t *global);
#endif
