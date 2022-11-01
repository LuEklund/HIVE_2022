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
	int value;
	value = 0;
	int i;
	i = 0;
	if(nptr[i] == '-' || nptr[i] == '+')
		i++;

	while(nptr[i] != '\0' && nptr[i] > 47 && nptr[i] < 58)
	{
		value = value*10 + nptr[i] - '0';
		i++;
	}
	if(nptr[0] == '-')
		value = value*-1;
	return(value);
}
