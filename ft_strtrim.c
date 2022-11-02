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
    int str_len;
    int y;
    int i;
    char *return_str;
    str_len = ft_strlen(s1)-1;
    i = 0;
    y = 0;
    while(s1[i] != '\0' && set[y] != '\0')
    {
        y = 0;
        while(s1[i] != set[y] && set[y] != '\0')
            y++;
        i++;
    }
    i--;
    y = 0;
    while(str_len > 0 && set[y] != '\0')
    {
        y = 0;
        while(s1[str_len] != set[y] && set[y] != '\0')
        {
            y++;
        }
        str_len--;
    }
    str_len++;
    return_str = (char *)malloc(sizeof(char)*(str_len-i+2));
    if(!return_str)
        return(0);
    y = 0;
    while(str_len+1-i > 0)
    {
        return_str[y] = *(s1+i+y);
        y++;
        str_len--;
    }
    return_str[y] = '\0';
    return(return_str);
}
