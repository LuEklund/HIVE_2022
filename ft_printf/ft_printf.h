/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:05:34 by leklund           #+#    #+#             */
/*   Updated: 2022/11/27 15:05:37 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	is_nbr(int n, int *int_return);
void	print_putchar(char c, int *int_return);
void	is_str(char *s, int *int_return);
void	put_percentage(char c, int *int_return);
void	is_unbr(unsigned int n, int *int_return);
void	is_hexa(unsigned long long num, int mod, int *int_return);

#endif
