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


static int eliminator_real_size(char const *s, char c)
{
    int i;
    i = 0;
    while(*s == c && *s != '\0')
        s++;
    while(*s != '\0')
    {
        while(*s != c && *s != '\0')
            s++;
        while(*s == c && *s != '\0')
            s++;
        i++;
    }
    return(i);
}

static void substr_mallocing(char const *s, char c, char **ptr_arr)
{
    int i;
    const char *checkpoint;
    int MainI;
    MainI = 0;
    while(*s != '\0')
    {
        i = 0;
        while(*s != c && *s != '\0')
        {
            s++;
            i++;
        }
        ptr_arr[MainI] = (char *)malloc(sizeof(char)*(i+1));
        ptr_arr[MainI][i--] = '\0';
        checkpoint = s;
        while(i >= 0)
        {
            ptr_arr[MainI][i] = *--s;
            i--;
        }
        s = checkpoint;
        while(*s == c && *s != '\0')
            s++;
        MainI++;
    }
}

char **ft_split(char const *s, char c)
{
    int i;
    char **ptr_arr;
    if(!s)
        return(0);
    i = 0;
    while(*s == c && *s != '\0')
        s++;
    i = eliminator_real_size(s,c);
    ptr_arr = malloc(sizeof(char *) * (i+1));
    if(!ptr_arr)
        return(0);
    ptr_arr[i] = NULL;
    substr_mallocing(s,c,ptr_arr);
   
    

    return(ptr_arr);
}