/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:26:05 by leklund           #+#    #+#             */
/*   Updated: 2023/01/10 18:26:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void	find_mid(t_info **info)
{
	t_stack	*mid;
	int		steps;

	steps = 0;
	mid = (*info)->smallest;
	steps = (*info)->a_size / 2;
	(*info)->steps = steps;
	steps--;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid = mid;
	steps = (*info)->a_size / 4;
	steps--;
	mid = (*info)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid_mid = mid;
}

void	put_half_in_b(t_info **info)
{
	while ((*info)->steps)
	{
		if (optimmal_path_is_up_a(&(*info)))
		{
			while ((*info)->a->value > (*info)->mid->value)
				rotate(&(*info), 'a');
		}
		else
		{
			while ((*info)->a->value > (*info)->mid->value)
				reverse_rotate(&(*info), 'a');
		}
		put_in_b(&(*info));
		(*info)->steps--;
	}
}

void	fix_b_stack_position(t_info **info)
{
	if ((*info)->b->value <= (*info)->first_mid_mid->value)
	{
		while ((*info)->b->value <= (*info)->first_mid_mid->value)
			rotate(&(*info), 'b');
	}
	else if ((*info)->b_last->value > (*info)->first_mid_mid->value)
	{
		while ((*info)->b_last->value > (*info)->first_mid_mid->value)
			reverse_rotate(&(*info), 'b');
	}
}

void	fix_first_a(t_info **info)
{
	if ((*info)->a_size == 3)
	{
		if ((*info)->a->larger == NULL)
			rotate(info, 'a');
		if ((*info)->a->next->larger != NULL && (*info)->a->next->larger != (*info)->a_last)
			swap(info, 'a');
		else if ((*info)->a->next->larger != (*info)->a_last)
			reverse_rotate(info, 'a');
		if ((*info)->a_last->larger == NULL && (*info)->a->next->larger != (*info)->a_last)
			swap(info, 'a');
	}
	else
		rotate(info, 'a');
}

void	start_sort(t_info **info)
{
	while ((*info)->a_size > 3)
	{
		find_mid(&(*info));
		put_half_in_b(&(*info));
		if ((*info)->first_mid_mid == NULL)
			(*info)->first_mid_mid = (*info)->mid_mid;
		fix_b_stack_position(&(*info));
		(*info)->smallest = (*info)->mid->larger;
	}
	if (!in_order(&(*info)->a))
		fix_first_a(info);
	start_pushing_a(info);
}
