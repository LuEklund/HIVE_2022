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
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int i = 0;
	char *str;
	str = (char *)malloc(sizeof(char)*(len + 1));
	if(str == NULL)
		return(NULL);
	while(len > 0)
	{
		str[i] = s[start + i];
		len--;
		i++;
	}
		str[i] = '\0';
	return(str);
}
