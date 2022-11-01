/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:02:49 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 15:02:52 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
static int ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int dst_size;
	int tot_size;
	dst_size = ft_strlen(dst);
	tot_size = dst_size + ft_strlen((char *) src);
	size_t i;
	int y;
	y = 0;
	i = dst_size;
	while(i < dstsize-1)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return(tot_size);
}