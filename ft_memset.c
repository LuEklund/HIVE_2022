/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:52 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 17:18:12 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
void *ft_memset(void *s, int c, size_t n)
{
	char *str = s;
	size_t i = 0;
	while(i < n)
	{
		str[i++] = (unsigned char)c;
	}
	return(s);
}
