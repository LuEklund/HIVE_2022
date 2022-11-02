/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:33:32 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 18:33:35 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
static void ft_bzero(void *s, size_t n)
{
	char *str = s;
	size_t i = 0;
	while(i < n)
	{
		str[i++] = '\0';
	}
}

void *ft_calloc(size_t nelem, size_t elsize)
{
	void *str;
	str = malloc(elsize*nelem);
	if(str)
		ft_bzero(str,nelem*elsize);
	return(str);
}