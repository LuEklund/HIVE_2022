/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:11:27 by leklund           #+#    #+#             */
/*   Updated: 2023/01/06 18:11:30 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	opimmal_path_is_up(t_info **info)
{
	t_stack	*curr;
	int		i;
	int		first_pos;
	int		last_pos;

	curr = (*info)->a;
	i = 1;
	first_pos = 0;
	last_pos = 0;
	while (curr)
	{
		if (curr->value < (*info)->mid->value)
		{
			if (!first_pos)
				first_pos = i;
			last_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (first_pos <= (*info)->a_size - last_pos)
		return (1);
	return (0);
}