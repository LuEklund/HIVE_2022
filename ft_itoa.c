/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:46:47 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 18:20:37 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	nblen(long int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	string_maker(int i, int isnegative, long int n, char *str)
{
	int	mod;

	mod = 0;
	while (i > isnegative)
	{
		i--;
		mod = n % 10;
		n = n / 10;
		str[i] = mod + '0';
	}
}

char	*ft_itoa(int nint)
{
	int			isnegative;
	char		*str;
	int			i;
	long int	n;

	n = nint;
	isnegative = 0;
	i = nblen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		isnegative = 1;
		n = n * -1;
		str[0] = '-';
	}
	str[i] = '\0';
	string_maker(i, isnegative, n, str);
	return (str);
}
