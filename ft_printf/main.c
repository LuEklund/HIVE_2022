/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:15:49 by leklund           #+#    #+#             */
/*   Updated: 2022/11/27 15:16:31 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	// char	*str = "HELLO!";
	int		amountT = 0;
	int		amountM = 0;
	// char	charC = 'c';
	// printf("cspdiuxX%");
	// printf("Hello%%s%i%%s\n", 9);2147483647
	// ft_printf("Mine:  %i | %s | %c | %% | %d |\n",21,str,charC,11);
	// printf("Their: %i | %s | %c | %% | %d |\n",21,str,charC,11);
	int i = 0;
	while(i < 1)
	{
		amountM = ft_printf("%u\n", NULL);
		amountT = printf("%u\n", NULL);
		i++;
		printf("MINE VALUE: %d\n", amountM);
		printf("THEIR VALUE: %d\n", amountT);
		printf("===========\n");
	}
	
	return (0);
}
	// va_list	check;
	// va_copy(check,*args);
	// if(!va_arg(check, int))
	// 	is_str("")
