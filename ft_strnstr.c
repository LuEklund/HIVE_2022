/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:47:25 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 17:47:28 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>


#include<stdio.h>

static int ft_strlen(char const *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}


char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	int y;
	int nlen;
	nlen = ft_strlen(needle);
	y = 0;
	i = 0;

	while(i < len)
	{
		if(haystack[i] == needle[y])
		{
			if(y+1 == nlen || haystack[i+1] == needle[y+1])
				y++;
		}	
		else
			y = 0;
		i++;
		if(y == nlen)
			return((char *)haystack+i-nlen);
	}
	return(0);
}




