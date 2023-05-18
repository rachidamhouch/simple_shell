#include "shell.h" 

/**
 *_strlen - this function calculate the length
 *@s: arg 1.
 *Return:The length of the string
 */
size_t	_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
