/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:10:30 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 12:10:33 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int value;
    int i;
    i = 0;
    value = 0;

    while(n > 0)
    {
        value = value + ((unsigned char)s1[i]-(unsigned char)s2[i]);
        if(s1[i] == '\0' || s2[i] == '\0')
            return(value);
        if(s1[i] != s2[i])
            return(value);
        n--;
        i++;
        
    }
    return(value);
}