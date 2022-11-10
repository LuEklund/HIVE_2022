/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:52:10 by leklund           #+#    #+#             */
/*   Updated: 2022/10/27 18:52:12 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

static int	overflow_return(int isnegative)
{
	if (isnegative)
		return (0);
	return (-1);
}

static int	blank_skipper(int i, const char *nptr)
{
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long int	value;
	int			isnegative;
	int			i;

	isnegative = 0;
	value = 0;
	i = 0;
	i = blank_skipper(i, nptr);
	if (nptr[i] == '-')
	{
		isnegative = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0' && nptr[i] > 47 && nptr[i] < 58))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
		if (value < 0)
			return (overflow_return(isnegative));
	}
	if (isnegative)
		return ((int)value * -1);
	return ((int) value);
}
