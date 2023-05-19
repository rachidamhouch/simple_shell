#include "shell.h"
/**
 * all - Read from fd.
 * @fd: arg 1.
 * @left: arg 2.
 * Return: The concatenated string
 */
static char	*all(int fd, char *left)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readed && !my_strchr(left, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		left = my_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

/**
 * get_line - Extract one line.
 * @line: arg 1.
 * Return: The extracted line
 */
static char	*get_line(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line, i);
	if (line[i] == '\n')
	{
		ptr[i] = '\n';
		ptr[i + 1] = '\0';
	}
	else
		ptr[i] = '\0';
	return (ptr);
}

/**
 * ft_left - Extract the remaining part of the string.
 * @line: arg 1..
 * Return: The remaining part of the string
 */
static char	*ft_left(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(my_strlen(line) - i + 1);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line + i + 1, my_strlen(line) - i);
	ptr[my_strlen(line) - i] = '\0';
	return (ptr);
}

/**
 * _getline - Read a line from fd.
 * @fd: arg 1.
 * @global: arg 2.
 * Return: The next line from the file descriptor,
 * or NULL on failure or end of file.
 */
char	*_getline(int fd, global_t *global)
{
	static char	*left;
	char		*line;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = all(fd, left);
	next_line = get_line(line);
	left = ft_left(line);
	global->left = left;
	free(line);
	return (next_line);
}
