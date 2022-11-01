/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:14:29 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 20:14:33 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
void *ft_memmove(void *dest, const void *src, size_t n)
{
	if(dest == NULL && src == NULL)
		return(0);
	if(dest > src)
	{
		char *dest1 = (char *)(dest + n);
		char *src1 = (char *)(src + n);
		while(n > 0)
		{
			dest1--;
			src1--;
			*dest1 = *src1;
			n--;
		}
		return(dest1);
	}
	else
	{
		char *dest1 = (char *)dest;
		char *src1 = (char *)src;
		size_t	i = 0;
		while(i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
		dest = dest1;
		return(dest);
	}
}