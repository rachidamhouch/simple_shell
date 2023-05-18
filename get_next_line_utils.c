#include "shell.h"

/**
 * my_memcpy - Copy memory area.
 * @dst: arg 1.
 * @src: arg 2.
 * @n: arg 3.
 * Return: Pointer.
 */
void	*my_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dst);
}

/**
 * my_strlen - Calculate the length.
 * @s: arg 1.
 * Return: The length.
 */
size_t	my_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

/**
 * my_strjoin - join two strings
 * @s1: arg 1.
 * @s2: arg 2.
 * Return: Pointer to the concatenated string.
 */
char	*my_strjoin(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s2)
		return (0);
	ls2 = my_strlen(s2);
	if (!s1)
		ls1 = 0;
	else
		ls1 = my_strlen(s1);
	ptr = malloc(ls1 + ls2 + 1);
	if (!ptr)
		return (0);
	if (!s1)
		my_memcpy(ptr, s2, ls2);
	else
	{
		my_memcpy(ptr, s1, ls1);
		my_memcpy(ptr + ls1, s2, ls2);
	}
	ptr[ls1 + ls2] = '\0';
	free(s1);
	return (ptr);
}

/**
 * my_strchr - locate first occurrence of a character.
 * @s: arg 1.
 * @c: arg 2.
 * Return: Pointer or NULL.
 */
char	*my_strchr(const char *s, int c)
{
	char	*n;

	n = (char *)s;
	if (!s)
		return (NULL);
	while (*n)
	{
		if (*n == (char) c)
			return (n);
		n++;
	}
	if (*n == (char) c)
		return (n);
	return (NULL);
}
