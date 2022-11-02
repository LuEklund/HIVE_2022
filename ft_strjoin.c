/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:46 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 18:39:19 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int ft_strlen(char const *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}



char *ft_strjoin(char const *s1, char const *s2)
{
	if(!s1 || !s2)
		return(0);
	char *str;
	int i = 0;
	int y = 0;
	int size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char)*(size+1));
	if(str == NULL)
		return(NULL);
	while(s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[y] != '\0')
	{
		str[i] = s2[y];
		i++;
		y++;
	}
	str[i] = '\0';
	return(str);
}
