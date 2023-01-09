/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:54:22 by leklund           #+#    #+#             */
/*   Updated: 2023/01/08 16:54:23 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	in_order(t_stack **stack)
{
	t_stack	*curr;

	curr = (*stack);
	while (curr)
	{
		if (curr->next == curr->larger)
			curr = curr->next;
		else if (curr->larger == NULL)
		{
			if (in_order(&curr->next))
				return (2);
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	find_largest_is_up(t_info **info)
{
	int	size;
	t_stack *curr;

	curr = (*info)->b;
	size = (*info)->b_size/2;
	while (size)
	{
		if (curr->larger == (*info)->a)
			return (1);
		curr = curr->next;
		size--;
	}
	return (0);
}

void	bring_largest_top_b(t_info **info)
{
	if (find_largest_is_up(info))
	{
		while((*info)->b->larger != (*info)->a)
		rotate(info, 'b');
	}
	else
	{
		while((*info)->b->larger != (*info)->a)
		reverse_rotate(info, 'b');
	}
}

void	start_pushing_a(t_info **info)
{
	while ((*info)->b_size)
	{
		while ((*info)->b->larger == (*info)->a)
			push(info, 'a');
		if ((*info)->b->next->larger == (*info)->a)
			swap(info, 'b');
		else
			bring_largest_top_b(info);
	}
}