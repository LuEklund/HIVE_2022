/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:33:32 by leklund           #+#    #+#             */
/*   Updated: 2022/10/29 18:33:35 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*str;
	size_t	bytes;

	if (nelem != 0 && elsize != 0)
	{
		bytes = nelem * elsize;
		if (bytes / elsize != nelem)
			return (NULL);
	}
	str = malloc (elsize * nelem);
	if (str)
		ft_bzero (str, nelem * elsize);
	return (str);
}
