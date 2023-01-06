/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:17:15 by leklund           #+#    #+#             */
/*   Updated: 2022/12/29 17:17:17 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf/ft_printf.h"

int	error_message(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	return (0);
}