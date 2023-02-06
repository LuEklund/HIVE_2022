/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:47:25 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 17:13:43 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	char const	*find_next;

	if ((!haystack || !needle) && len == 0)
		return (0);
	find_next = haystack;
	needle_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	find_next = ft_strchr(find_next, needle[0]);
	while (find_next)
	{
		if (find_next - haystack + needle_len > len)
			return (0);
		if (!(ft_strncmp(find_next, needle, needle_len)))
			return ((char *)find_next);
		find_next++;
		find_next = ft_strchr(find_next, needle[0]);
	}
	return (0);
}
