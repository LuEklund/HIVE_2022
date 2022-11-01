/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:07:47 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 16:07:51 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	int value;
    size_t i;
    i = 0;
    value = 0;

    while(n > i)
    {
        if(str1[i] != str2[i])
            return(str1[i]-str2[i]);
        i++;
    }
    return(value);
}