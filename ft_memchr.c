/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:56:47 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 12:56:55 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    i = 0;
    char *str;
    str = (char *)s;
    while(n > i)
    {
        if(str[i] == c)
            return(str+i);
        i++;
    }
    return(0);
}