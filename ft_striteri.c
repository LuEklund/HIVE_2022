/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:35:26 by leklund           #+#    #+#             */
/*   Updated: 2022/10/31 18:35:28 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;
	i = 0;
	
	while(*s)
	{
		f(i,s);
		i++;
		s++;
	}
}