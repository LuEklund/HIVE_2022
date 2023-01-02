/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:13:44 by leklund           #+#    #+#             */
/*   Updated: 2022/12/30 12:13:45 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../ft_printf/ft_printf.h"

int	is_in_order(t_info **info)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = (*info)->a;
	b_stack = (*info)->b;
	while (a_stack && a_stack->next == a_stack->larger)
		a_stack = a_stack->next;
	if (a_stack == NULL)
		return (1);
	return (0);
}

void	what_to_doer(t_info **info)
{
	int	half_stack_size;

	half_stack_size = (*info)->a_size / 2;
	ft_printf("curr[%i], middle[%i]\n", (*info)->a->value, (*info)->mid->value);
	while (!is_in_order(info))
	{
		if (!half_stack_size)
			break ;
		else if ((*info)->a->value < (*info)->mid->value)
		{
			half_stack_size--;
			ft_printf("pa\n");
			do_op(&(*info)->a, &(*info)->b, "Push");
		}
		else
		{
			ft_printf("ra\n");
			rotate(&(*info)->a);
		}
	}
}
