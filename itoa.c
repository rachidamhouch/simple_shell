#include "shell.h"

/**
 *ft_abs - abs.
 *@nb: arg 1.
 *Return: pos num.
 */
static int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/**
 *ft_nbrpow - pow.
 *@nbr: arg 1.
 *Return: pow.
 */
static int	ft_nbrpow(int nbr)
{
	int	pow;

	pow = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		pow++;
	}
	return (pow);
}

/**
 *_itoa - int to array of chars.
 *@n: arg 1.
 *Return: string.
 */
char	*_itoa(int n)
{
	char	*res;
	int		len;
	int		neg;

	neg = n < 0;
	len = ft_nbrpow(n) + neg;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
