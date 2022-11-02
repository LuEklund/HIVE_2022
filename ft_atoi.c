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
int ft_atoi(const char *nptr)
{
	long int value;
	int isNegative;
	isNegative = 0;
	value = 0;
	int i;
	i = 0;
	while((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if(nptr[i] == '-')
	{
		isNegative = 1;
		i++;
	}
	else if(nptr[i] == '+')
		i++;
	while((nptr[i] != '\0' && nptr[i] > 47 && nptr[i] < 58))
	{
		value = value*10 + nptr[i] - '0';
		i++;
		if(value < 0)
		{
			if (isNegative)
				return(0);
			return(-1);
		}
	}
	if (isNegative)
		return((int)value * -1);
	return ((int) value);
}
