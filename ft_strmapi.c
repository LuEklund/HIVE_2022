/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:07:28 by leklund           #+#    #+#             */
/*   Updated: 2022/10/31 18:07:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
static int ft_strlen(char const *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	if(!s || !f)
		return(0);
	char *str_return;
	int len;
	int i;
	i = 0;
	len = ft_strlen(s);
	str_return = (char *)malloc(sizeof(char *)*(len + 1));
	if(!str_return)
		return(0);
	
	while(s[i])
	{
		str_return[i] = f(i,s[i]);
		i++;
	}
	str_return[i] = '\0';
	return(str_return);
}