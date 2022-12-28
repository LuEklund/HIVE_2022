/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:14:29 by leklund           #+#    #+#             */
/*   Updated: 2022/11/07 15:41:43 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;

	if (dest == NULL && src == NULL)
		return (0);
	if (dest > src)
	{
		dest1 = (char *)(dest + n);
		src1 = (char *)(src + n);
		while (n > 0)
		{
			dest1--;
			src1--;
			*dest1 = *src1;
			n--;
		}
		return (dest1);
	}
	else
		return (ft_memcpy(dest, src, n));
}
