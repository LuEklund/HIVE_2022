/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:21:16 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 19:12:48 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static unsigned int ft_strlen(const char *s)
{
	int i;
	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return(i);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int i = 0;
	char *str;
	if(!s)
		return(0);
	
	if(start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char)*(1));
		str[0] = '\0';
		return(str);
	}
	str = (char *)malloc(sizeof(char)*(len + 1));
	if(str == NULL)
		return(NULL);
	while(len > 0)
	{
		str[i] = s[start+i];
		len--;
		i++;
	}
		str[i] = '\0';
	return(str);
}
