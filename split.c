#include "shell.h"
/**
 *m_error - Frees memory for given array
 *@arr: arg 1.
 *Return:NULL
 */
static char	**m_error(char	**arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

/**
 *ft_count_words - Counts the number of words in a string
 *@str: arg 1.
 *@charset: arg 2.
 *Return: The number of words
 */
static int	ft_count_words(char const *str, char charset)
{
	int	i;
	int	nbr_w;

	nbr_w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == charset))
			i++;
		if (str[i])
			nbr_w++;
		while (str[i] && !(str[i] == charset))
			i++;
	}
	return (nbr_w);
}

/**
 *ft_word_len - calculate the lenth of word in a string
 *@str: arg 1.
 *@charset: arg 2.
 *Return: The length of the word
 */
static int	ft_word_len(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == charset))
		i++;
	return (i);
}

/**
 *ft_word_grep - Extracts a word from a string
 *@str: arg 1.
 *@charset: arg 2.
 *Return: pointer to the extracted word
 */
static char	*ft_word_grep(char const *str, char charset)
{
	int		len_w;
	int		i;
	char	*word;

	i = 0;
	len_w = ft_word_len(str, charset);
	word = malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (i < len_w)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

/**
 *split - string array of substrings based on a delimiter
 *@s: arg 1.
 *@c: arg 2.
 *Return: An array of pointers to the substrings
 */
char	**split(char const *s, char c)
{
	int			i;
	char		**splited;

	if (!s)
		return (NULL);
	i = 0;
	splited = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splited)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			splited[i] = ft_word_grep(s, c);
			if (!splited[i])
				return (m_error(splited));
			i++;
		}
		while (*s && !(*s == c))
			s++;
	}
	splited[i] = 0;
	return (splited);
}
