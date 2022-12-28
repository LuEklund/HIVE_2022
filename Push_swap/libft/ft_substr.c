/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:21:16 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 19:12:48 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	size_to_malloc(char const *s, unsigned int start, size_t len)
{
	int	i;

	i = 0;
	while (len > 0 && s[start + i] != '\0')
	{
		i++;
		len--;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) *(1));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) *(size_to_malloc(s, start, len) + 1));
	if (str == NULL)
		return (NULL);
	while (len > 0 && s[i] != '\0')
	{
		str[i] = s[start + i];
		len--;
		i++;
	}
		str[i] = '\0';
	return (str);
}
