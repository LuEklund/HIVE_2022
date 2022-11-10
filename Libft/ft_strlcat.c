/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:02:49 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 16:52:23 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	string_length(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	src_len;

	len = 0;
	src_len = string_length(src);
	if (size == 0)
		return (src_len + len);
	while (*dst && size > 0)
	{
		dst++;
		len++;
		size--;
	}
	while (*src && size > 1)
	{
		size--;
		*dst++ = *src++;
	}
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (src_len + len);
}
