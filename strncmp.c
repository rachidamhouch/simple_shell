#include "shell.h"
/**
 *_strncmp - Compares two strings 
 *@s1:The first string
 *@s2:The second string
 *@n:the maximum number of characters to compare
 *Return:integer equalto,less than or greater than
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
