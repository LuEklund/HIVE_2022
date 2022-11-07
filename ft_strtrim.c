/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:42:08 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 18:05:32 by leklund          ###   ########.fr       */
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

static int	trim_start(char const *s1, char const *set)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (s1[i] != '\0' && set[y] != '\0')
	{
		y = 0;
		while (s1[i] != set[y] && set[y] != '\0')
			y++;
		if (set[y] != '\0')
			i++;
	}
	return (i);
}

static int	trim_end(char const *s1, char const *set, int str_len)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (str_len > 0 && set[y] != '\0')
	{
		y = 0;
		while (s1[str_len - 1] != set[y] && set[y] != '\0')
			y++;
		if (set[y] != '\0')
			i++;
		str_len--;
	}
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[i] = s[start + i];
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		from_start;
	int		from_end;
	int		str_len;
	char	*return_str;

	if (!s1)
		return (0);
	str_len = ft_strlen(s1);
	from_start = trim_start(s1, set);
	if (from_start >= str_len)
	{
		return_str = (char *)malloc(sizeof(char) * 1);
		return_str[0] = '\0';
		return (return_str);
	}
	from_end = trim_end(s1, set, str_len);
	return_str = ft_substr(s1, from_start, str_len - from_start - from_end);
	return (return_str);
}
