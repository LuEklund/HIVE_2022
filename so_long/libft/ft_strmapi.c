/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:07:28 by leklund           #+#    #+#             */
/*   Updated: 2022/10/31 18:07:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_return ;
	int		len;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str_return = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_return)
		return (0);
	while (s[i])
	{
		str_return[i] = f(i, s[i]);
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}
