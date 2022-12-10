/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:52:10 by leklund           #+#    #+#             */
/*   Updated: 2022/11/27 14:52:12 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	convertion(const char *str, va_list	*args, int *int_return)
{
	if (*(str + 1) == 'i' || *(str + 1) == 'd')
		is_nbr(va_arg(*args, int), int_return);
	else if (*(str + 1) == 's')
		is_str(va_arg(*args, char *), int_return);
	else if (*(str + 1) == 'c')
		print_putchar((char)va_arg(*args, unsigned int), int_return);
	else if (*(str + 1) == '%')
		print_putchar(*str, int_return);
	else if (*(str + 1) == 'u')
		is_unbr(va_arg(*args, int), int_return);
	else if (*(str + 1) == 'x')
		is_hexa(va_arg(*args, unsigned), 32, int_return);
	else if (*(str + 1) == 'X')
		is_hexa(va_arg(*args, unsigned), 0, int_return);
	else if (*(str + 1) == 'p')
	{
		is_str("0x", int_return);
		is_hexa(va_arg(*args, unsigned long long), 32, int_return);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		int_return;

	index = 0;
	int_return = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			convertion(&str[index], &args, &int_return);
			int_return--;
			index++;
		}
		else
			write(1, &str[index], 1);
		index++;
		int_return++;
	}
	va_end(args);
	return (int_return);
}
