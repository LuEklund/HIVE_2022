/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:47:49 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 18:51:02 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>


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

char *ft_strdup(const char *s)
{
	int size;
	size = ft_strlen(s);
	char *str;
	str = (char *)malloc(sizeof(char)*(size + 1));
	if(!str)
		return(0);

	int i;
	i = 0;
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}