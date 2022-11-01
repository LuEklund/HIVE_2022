/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:42:08 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 18:58:40 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
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

char *ft_strtrim(char const *s1, char const *set)
{
	char *str;
	char *return_str;
	str = (char *)malloc(sizeof(char)*(ft_strlen(s1) + 1));
	int i;
	i = 0;
	int y;
	y = 0;
	int same;
	same = 0;
	while(s1[i] != '\0')
	{
		str[i] = s1[i];
		while(set[y] != '\0')
		{
			if(set[y] == s1[i])
				str[i] = '\0';
			y++;
		}
		if(s1[i] == str[i])
			same++;
		y = 0;
		i++;
	}
	return_str = (char *)malloc(sizeof(char)*(same + 1));
	i = 0;
	while(s1[i] != '\0')
	{
		if(s1[i] == str[i])
		{
			return_str[y] = s1[i];
			y++;
		}
		i++;
	}
	
	return(return_str);
}
