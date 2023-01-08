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
	mid = (*info)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid_mid = mid;
	if (!(*info)->first_mid_mid)
		(*info)->first_mid_mid = mid;
	steps = (*info)->a_size / 2;
	(*info)->steps = steps;
	mid = (*info)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid = mid;
	// st_info(info);
}

void	fix_b_stack_position(t_info **info)
{
	// while ((*info)->a_last->value >= (*info)->first_mid_mid->value)
	// 	reverse_rotate(&(*info), 'b');
	if ((*info)->b->value < (*info)->first_mid_mid->value)
	{
		while ((*info)->b->value <= (*info)->first_mid_mid->value)
			rotate(&(*info), 'b');
	}
	else
	{
		while ((*info)->b_last->value >= (*info)->first_mid_mid->value)
			reverse_rotate(&(*info), 'b');
	}
}

void	put_half_in_b(t_info **info)
{
	while ((*info)->steps)
	{
		if (opimmal_path_is_up_a(&(*info)))
		{
			while ((*info)->a->value >= (*info)->mid->value)
				rotate(&(*info), 'a');
		}
		else
		{
			while ((*info)->a->value >= (*info)->mid->value)
				reverse_rotate(&(*info), 'a');
		}
		put_in_b(&(*info));
		// loop(&(*info), 'a', "STACK A");
		// loop(&(*info), 'b', "STACK B");
		// ft_printf("Last element in stack[A] is [%i]\n", (*info)->a_last->value);
		// ft_printf("Last element in stack[B] is [%i]\n", (*info)->b_last->value);
		(*info)->steps--;
	}
}

void	start_sort(t_info **info)
{
	while ((*info)->a_size > 3)
	{
		find_mid(&(*info));
		// loop(&(*info), 'a', "STACK A");
		// loop(&(*info), 'b', "STACK B");
		put_half_in_b(&(*info));
		fix_b_stack_position(&(*info));
		// loop(&(*info), 'a', "STACK A");
		// loop(&(*info), 'b', "STACK B");
		// ft_printf("Last element in stack[A] is [%i]\n", (*info)->a_last->value);
		// ft_printf("Last element in stack[B] is [%i]\n", (*info)->b_last->value);
		(*info)->smallest = (*info)->mid;
	}
}
