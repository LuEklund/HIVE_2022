/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:10:58 by leklund           #+#    #+#             */
/*   Updated: 2022/11/19 12:10:59 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#include <unistd.h>
#include <stdlib.h>
//----------------------------------
//----------------------------------
//-----------============-----------
//REMOVE INCLUDES ILLEGAL!
# include <stdio.h>
//-----------============-----------
//----------------------------------
//----------------------------------
//----------------------------------
//----------------------------------
//-----------============-----------
//REMOVE INCLUDES ILLEGAL?????
char	*get_next_line(int fd);
//-----------============-----------
//----------------------------------
//----------------------------------

typedef	struct	s_list
{
	int			last;
	char		*save;
}				t_list;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
void	free_all(t_list *mem, char *tmp);




#endif