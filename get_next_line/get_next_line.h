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
#  define BUFFER_SIZE 5
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

char	*get_next_line();
void get_next_line_utils();

typedef	struct	s_list
{
	void		*content;
	struct		s_list *next;
}				t_list;


#endif