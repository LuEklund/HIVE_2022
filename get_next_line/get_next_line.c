/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:10:45 by leklund           #+#    #+#             */
/*   Updated: 2022/11/19 12:10:53 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


void readding()
{
	
}

char	*get_next_line(int fd)
{
	char *tmp;
	tmp = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1);
	read(fd,tmp,BUFFER_SIZE);
	return (tmp);
}

