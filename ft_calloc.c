/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:33:32 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 18:33:35 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
void *ft_calloc(size_t nelem, size_t elsize)
{
	void *str;
	str = malloc(elsize*nelem);
	if(!str)
		return(0);
	return(str);
}