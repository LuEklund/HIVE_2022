/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:32:10 by leklund           #+#    #+#             */
/*   Updated: 2022/10/27 19:41:02 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

static int ft_strlen(const char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	
	size_t i;
	int src_len;
	src_len = ft_strlen(src);
	i = 0;
	if(size == 0)
	 	return(src_len);
	while(src[i] != '\0' && size-1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(src_len);
}