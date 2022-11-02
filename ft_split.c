/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:39:43 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 19:39:45 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
static char *ft_strchr(const char *s, int c)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
            return((char *)s+i);
        i++;
    }
    return(0);
}

char **ft_split(char const *s, char c)
{
    char const *find_next;
    char const *checkpoint;
    checkpoint = s;
    find_next = s;

    //count amount of deliminators(c) in string(s)
    int i;
    i = 0;
    while((find_next = ft_strchr(find_next,c)))
    {
        i++;
        find_next++;
    }
    char **ptr_arr;
    ptr_arr = malloc(sizeof(char *) * (i+2));
    int i2;
    int Arri;
    Arri = 0;
    while(i >= 0)
    {
        i2 = 0;
        while(*s && *s != c)
        {
            i2++;
            s++;
        }
        i--;
        s++;

        ptr_arr[Arri++] = (char *)malloc(sizeof(char)*(i2+1));
    }
    ptr_arr[Arri] = (char *)malloc(sizeof(char)*(1));
    s = checkpoint;
    i = 0;
    while(Arri >= 0)
    {
        i2 = 0;
        while(*s && *s != c)
        {
            ptr_arr[i][i2] = *s;
            i2++;
            s++;
        }
        ptr_arr[i][i2] = '\0';
        i++;
        Arri--;
        s++;
    }
    return(ptr_arr);
}
