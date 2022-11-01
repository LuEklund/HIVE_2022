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

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	i = 0;
	while(src[i] != '\0')
	{
		if(i < dstsize-1)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return(i);
}