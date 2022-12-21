/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:25:59 by leklund           #+#    #+#             */
/*   Updated: 2022/12/19 17:26:01 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	rec_cross_close(void)
{
	exit(0);
}

void	error_print(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}

void	error_message(char *str)
{
	ft_putstr_fd("Error\n", 1);
	perror(str);
	exit(0);
}
