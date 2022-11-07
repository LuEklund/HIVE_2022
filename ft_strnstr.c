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
#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	else
		return (0);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	while (n > 0)
	{
		value = value + ((unsigned char)s1[i] -(unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (value);
		if (s1[i] != s2[i])
			return (value);
		n--;
		i++;
	}
	return (value);
}

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
