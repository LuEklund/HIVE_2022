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
	int	i;
	int	pos;
	t_stack *curr;

	i = 0;
	pos = 0;
	curr = (*info)->b;
	size = (*info)->b_size / 2;
	while (curr)
	{
		if (curr->larger == (*info)->a)
		{
			pos = i;
			break ;
		}
		curr = curr->next;
		i++;
	}
	if (!pos)
		return (0);
	if (size - pos >= 0)
		return (1);
	else
		return (-1);
}

// void	bring_largest_top_b(t_info **info)
// {
// 	int	way;

// 	way = find_largest_is_up(info);
// 	if (way == 1)
// 	{
// 		while((*info)->b->larger != (*info)->a)
// 			rotate(info, 'b');
// 		// op_exe(info, &rotate, 'b');
// 	}
// 	else if (way == -1)
// 	{
// 		while((*info)->b->larger != (*info)->a)
// 		reverse_rotate(info, 'b');
// 	}
// }

void	bring_largest_top_b(t_info **info)
{
	int	way;

	way = find_largest_is_up(info);
	if (way == 1)
	{
		while ((*info)->b->larger != (*info)->a)
		{
			if ((*info)->b->next->larger != (*info)->a && ((*info)->b->value > (*info)->a_last->value || (*info)->a_last->larger == NULL))
			{
				push(info, 'a');
				rotate_r(info);
			}
			else
				rotate(info, 'b');
		}
		
	}
	else if (way == -1)
	{
		while((*info)->b->larger != (*info)->a)
		reverse_rotate(info, 'b');
	}
	else
		reverse_rotate(info, 'a');
}

void	start_pushing_a(t_info **info)
{
	while ((*info)->b_size)
	{
		while ((*info)->b && (*info)->b->larger == (*info)->a)
			push(info, 'a');
		if ((*info)->b && (*info)->b->next->larger == (*info)->a)
			swap(info, 'b');
		else if ((*info)->b)
			bring_largest_top_b(info);
	}
}

