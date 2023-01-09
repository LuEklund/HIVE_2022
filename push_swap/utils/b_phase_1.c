/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_phase_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:49:20 by leklund           #+#    #+#             */
/*   Updated: 2023/01/08 10:49:21 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	opimmal_path_is_up_b_smaller(t_info **info)
{
	t_stack	*curr;
	int		i;
	int		first_pos;
	int		last_pos;

	curr = (*info)->b;
	i = 1;
	first_pos = 0;
	last_pos = 0;
	while (curr)
	{
		if (curr->value < (*info)->mid_mid->value)
		{
			if (!first_pos)
				first_pos = i;
			last_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (!first_pos)
		return (0);
	if (first_pos <= (*info)->b_size - last_pos)
		return (1);
	return (-1);
}

int	opimmal_path_is_up_b_larger(t_info **info)
{
	t_stack	*curr;
	int		i;
	int		first_pos;
	int		last_pos;

	curr = (*info)->b;
	i = 1;
	first_pos = 0;
	last_pos = 0;
	while (curr)
	{
		if (curr->value >= (*info)->mid_mid->value)
		{
			if (!first_pos)
				first_pos = i;
			last_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (!first_pos)
		return (0);
	if (first_pos <= (*info)->b_size - last_pos)
		return (1);
	return (-1);
}

void	put_with_lower_half(t_info **info)
{
	// int	way;

	if (!(*info)->b || (*info)->b->value < (*info)->mid_mid->value)
		return ;
	else
	{
		// way = opimmal_path_is_up_b_smaller(&(*info));
		// if (way == 1)
		// {
		if (opimmal_path_is_up_b_smaller(&(*info)))
		{
			while ((*info)->b->value >= (*info)->mid_mid->value)
				rotate(&(*info), 'b');
		}
		// }
		// else if (way == -1)
		// {
		// 	while ((*info)->b->value >= (*info)->mid_mid->value)
		// 		reverse_rotate(&(*info), 'b');
		// }
	}
}

void	put_with_higher_half(t_info **info)
{
	// int	way;

	if (!(*info)->b || (*info)->b_last->value >= (*info)->mid_mid->value)
		return ;
	else
	{
		// way = opimmal_path_is_up_b_larger(&(*info));
		// if (way == 1)
		// {
		if (opimmal_path_is_up_b_larger(&(*info)))
		{
			while ((*info)->b_last->value < (*info)->mid_mid->value)
				rotate(&(*info), 'b');
		}
	// 	}
	// 	else if (way == -1)
	// 	{
	// 		while ((*info)->b_last->value < (*info)->mid_mid->value)
	// 			reverse_rotate(&(*info), 'b');
	// 	}
	}
}

void	put_in_b(t_info **info)
{
	//check if b stack exists
	if ((*info)->a->value < (*info)->mid_mid->value)
		put_with_lower_half(&(*info));
	else
		put_with_higher_half(&(*info));
	// (*info)->b_size++;
	// (*info)->a_size--;
	push(&(*info), 'b');

}