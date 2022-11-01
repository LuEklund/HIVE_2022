/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:35:39 by leklund           #+#    #+#             */
/*   Updated: 2022/10/31 16:38:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
static void ft_putchar_fd(char c, int fd)
{
	write(fd,&c,1);
}

void ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-',fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10,fd);
		ft_putchar_fd(n % 10 + '0',fd);
	}
	else
	{
		ft_putchar_fd(n + '0',fd);
	}
}
