/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:49:07 by leklund           #+#    #+#             */
/*   Updated: 2023/01/06 17:49:08 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void	find_mid(t_info **info)
{
	t_stack	*mid;
	int		steps;

	steps = (*info)->a_size / 4;
	(*info)->orig_size = (*info)->a_size;
	mid = (*info)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid_mid = mid;
	steps = (*info)->a_size / 4;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid = mid;
}

void	start_sort(t_info **info)
{
	find_mid(&(*info));
	loop(&(*info)->a, "STACK A");
	loop(&(*info)->b, "STACK B");
	while ((*info)->b_size < (*info)->orig_size / 2)
	{
		if (opimmal_path_is_up(&(*info)))
		{
			while ((*info)->a->value > (*info)->mid->value)
				rotate(&(*info), 'a');
		}
		else
		{
			while ((*info)->a->value > (*info)->mid->value)
				reverse_rotate(&(*info), 'a');
		}
		(*info)->b_size++;
		push(&(*info), 'b');
		loop(&(*info)->a, "STACK A");
		loop(&(*info)->b, "STACK B");
	}
}
