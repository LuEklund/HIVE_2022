/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:18:21 by leklund           #+#    #+#             */
/*   Updated: 2022/11/27 16:18:24 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_putchar(char c, int *int_return)
{
	write(1, &c, 1);
	*int_return += 1;
}

void	is_str(char *s, int *int_return)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			print_putchar(s[i], int_return);
			i++;
		}
	}
	else
		is_str("(null)", int_return);
}

void	is_hexa(unsigned long long num, int mod, int *int_return)
{
	if (num >= 16)
	{
		is_hexa(num / 16, mod, int_return);
		is_hexa(num % 16, mod, int_return);
	}
	else if (num >= 10)
	{
		print_putchar(num + 7 + mod + '0', int_return);
	}
	else
		print_putchar(num + '0', int_return);
}

void	is_nbr(int n, int *int_return)
{
	if (n == -2147483648)
	{
		print_putchar('-', int_return);
		print_putchar('2', int_return);
		n = 147483648;
	}
	if (n < 0)
	{
		print_putchar('-', int_return);
		n = n * -1;
	}
	if (n >= 10)
	{
		is_nbr(n / 10, int_return);
		print_putchar(n % 10 + '0', int_return);
	}
	else
	{
		print_putchar(n + '0', int_return);
	}
}

void	is_unbr(unsigned int n, int *int_return)
{
	if (n >= 10)
	{
		is_unbr(n / 10, int_return);
		print_putchar(n % 10 + '0', int_return);
	}
	else
	{
		print_putchar(n + '0', int_return);
	}
}
