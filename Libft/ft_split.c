/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:39:43 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 18:09:03 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	eliminator_real_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
		i++;
	}
	return (i);
}

static void	substr_filler(char **ptr_arr, int main_index, int i, const char *s)
{
	while (i >= 0)
	{
		ptr_arr[main_index][i] = *--s;
		i--;
	}
}

static int	free_all(int main_index, char **ptr_arr)
{
	while (main_index > 0)
	{
		main_index--;
		free(ptr_arr[main_index]);
	}
	free(ptr_arr);
	return (0);
}

static int	substr_mallocing(char const *s, char c, char **ptr_arr)
{
	int			i;
	int			main_index;

	main_index = 0;
	while (*s != '\0')
	{
		i = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			i++;
		}
		ptr_arr[main_index] = (char *)malloc(sizeof(char) * (i + 1));
		if (!ptr_arr[main_index])
			return (free_all(main_index, ptr_arr));
		else
		{
			ptr_arr[main_index][i--] = '\0';
			substr_filler(ptr_arr, main_index, i, s);
			while (*s == c && *s != '\0')
				s++;
			main_index++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr_arr;

	if (!s)
		return (0);
	i = 0;
	while (*s == c && *s != '\0')
		s++;
	i = eliminator_real_size(s, c);
	ptr_arr = malloc(sizeof(char *) * (i + 1));
	if (!ptr_arr)
		return (0);
	ptr_arr[i] = NULL;
	if (!substr_mallocing(s, c, ptr_arr))
		return (0);
	return (ptr_arr);
}
