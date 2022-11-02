/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:04:02 by leklund           #+#    #+#             */
/*   Updated: 2022/10/26 11:13:42 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int len (const char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);

}

char *ft_strrchr(const char *s, int c)
{
	int	length;
	length = len(s);
	while(length >= 0)
	{
		if(s[length] == c)
			return((char *)s+length);
		length--;
	}
	return(0);
}
