/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:11:09 by leklund           #+#    #+#             */
/*   Updated: 2022/11/19 12:11:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
//modified to check if str = NULL return 0, so it works with strjoin
int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
//modified to ignore if s1 == NULL
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		y;

	if (!s2)
		return (0);
	i = 0;
	y = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		str[i] = s2[y];
		i++;
		y++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && size -1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*str;
	int		i;

	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	free_all(t_list *mem, char *tmp)
{
	if (mem->save != NULL)
	{
        free (mem->save);
        mem->save = NULL;
    }
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}