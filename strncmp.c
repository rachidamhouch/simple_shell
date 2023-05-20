#include "shell.h"

/**
 *_strncmp - Compares two strings.
 *@s1: arg 1.
 *@s2: arg 2.
 *@n: arg 3.
 *Return: 0 if equal.
 */
int	_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
