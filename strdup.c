#include "shell.h"

/**
 * _strdup - duplicates a string.
 * @s1: arg 1.
 * Return: the new string.
 */
char	*_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*src_copy;

	len = 0;
	index = -1;
	while (s1[len])
		len++;
	src_copy = malloc(sizeof(char) * (len + 1));
	if (!src_copy)
		return (NULL);
	while (s1[++index])
		src_copy[index] = s1[index];
	src_copy[index] = 0;
	return (src_copy);
}
