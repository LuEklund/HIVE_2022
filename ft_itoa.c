/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:46:47 by leklund           #+#    #+#             */
/*   Updated: 2022/10/28 18:46:51 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int nblen(int nb)
{
	int i;
	i = 1;
	if(nb < 0)
	{
		i++;
		nb = nb*-1;
	}
	while(nb > 10)
	{
		nb = nb/10;
		i++;
	}
	return(i);
}


char *ft_itoa(int n)
{
	int mod;
	int isNegative;
	char *str;
	int i;
	mod = 0;
	isNegative = 0;
	i = nblen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if(n < 0)
	{
		isNegative = 1;
		n=n*-1;
		str[0] = '-';
	}
	str[i+1] = '\0';
	while(i > 0+isNegative)
	{
		i--;
		mod = n % 10;
		n = n / 10;
		str[i] = mod + '0';
	}
	return(str);
}