/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:52 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 16:44:36 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
void ft_bzero(void *s, size_t n)
{
	char *str = s;
	size_t i = 0;
	while(i < n)
	{
		str[i++] = '\0';
	}
}
