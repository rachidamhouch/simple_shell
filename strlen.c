#include "shell.h"

/**
 *_strlen - calculate the length.
 *@s: arg 1.
 *Return:The length.
 */
size_t	_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
