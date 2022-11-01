/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:45:18 by leklund           #+#    #+#             */
/*   Updated: 2022/10/25 17:18:08 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

/*Takes n amount of characters from src and fills them into dest (including null-terminator )*/
void *ft_memcpy(void *dest, const void *src, size_t n)
{
	if(dest == NULL && src == NULL)
		return(0);
	char *dest1 = (char *)dest;
	char *src1 = (char *)src;
	size_t	i = 0;
	while(i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	dest = dest1;
	return(dest);
}

