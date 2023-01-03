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

int	in_order(t_stack **stack, char c)
{
	t_stack	*curr;

	curr = *stack;
	if (!curr)
		return (1);
	if (c == 'A')
	{
		while (curr->next)
		{
			if (curr->next == curr->larger)
				curr = curr->next;
			else
				return (0);
		}
	}
	else if (c == 'B')
	{
		while (curr->next)
		{
			if (curr == curr->next->larger)
				curr = curr->next;
			else
				return (0);
		}
	}
	return (1);
}

int	shift_up_a(t_stack **stack_a, int mid, int size)
{
	t_stack	*curr;
	int		i;
	int		first_pos;
	int		last_pos;

	curr = (*stack_a)->next;
	i = 1;
	first_pos = 0;
	last_pos = 0;
	while (curr->next)
	{
		if (curr->value < mid)
		{
			if (!first_pos)
				first_pos = i;
			last_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (curr->value < mid)
	{
		if (!first_pos)
			first_pos = i;
		last_pos = i;
	}
	// mid = size / 2;
	// ft_printf("FIRST[%i]\nLAST[%i]\n",first_pos, last_pos,);
	// ft_printf("top[%i] bot[%i]\n",first_pos, size - last_pos);
	if (!first_pos)
		return (0);
	if (first_pos <= size - last_pos)
		return (1);
	else
		return (0);
}

int	want_swap(t_stack **stack, char c)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	if (c == 'A')
	{
		if ((*stack)->value > (*stack)->next->value)
			return (1);
	}
	else if (c == 'B')
	{
		if ((*stack)->value < (*stack)->next->value)
			return (1);
	}
	return (0);
}

void	push_a_done(t_info **info)
{
	t_stack	*curr;

	curr = (*info)->b;
	if (!curr)
		return ;
	while (curr->next)
	{
		(*info)->moves++;
		ft_printf("pb\n");
		push(&(*info)->b, &(*info)->a);
	}
	(*info)->moves++;
	ft_printf("pb\n");
	push(&(*info)->b, &(*info)->a);
}

void	ss(t_info **info)
{
	ft_printf("ss\n");
	(*info)->moves++;
	swap(&(*info)->a);
	swap(&(*info)->b);
}

void	what_to_doer(t_info **info)
{
	// int	half_stack_size;

	// half_stack_size = (*info)->a_size / 2;
	ft_printf("curr[%i], middle[%i]\n", (*info)->a->value, (*info)->mid->value);
	while (!in_order(&(*info)->a, 'A') || !in_order(&(*info)->b,'B'))
	{
		printf("\n\n============================\n");
		// if (!(*info)->a_size / 2 || (*info)->a_size-1 <= (*info)->b_size)
		// 	break ;
		if (want_swap(&(*info)->a, 'A') && want_swap(&(*info)->b, 'B'))
		{
			ss(info);
		}
		else if ((*info)->a->value < (*info)->mid->value)
		{
			(*info)->a_size--;
			(*info)->b_size++;
			(*info)->moves++;
			ft_printf("pb\n");
			do_op(&(*info)->a, &(*info)->b, "Push");
		}
		else
		{
			// ft_printf("curr value[%i]\n", (*info)->a->value);
			if (shift_up_a(&(*info)->a, (*info)->mid->value, (*info)->a_size))
			{
				while ((*info)->a->value >= (*info)->mid->value)
				{
					if (want_swap(&(*info)->a, 'A') && want_swap(&(*info)->b, 'B'))
						ss(info);
					(*info)->moves++;
					ft_printf("ra\n");
					rotate(&(*info)->a);
				}
			}
			else
			{
				while ((*info)->a->value >= (*info)->mid->value)
				{
					if (want_swap(&(*info)->a, 'A') && want_swap(&(*info)->b, 'B'))
						ss(info);
					(*info)->moves++;
					ft_printf("rra\n");
					reverse_rotate(&(*info)->a);
				}
			}
		}
		
		loop(&(*info)->a,"A");
		loop(&(*info)->b,"B");
	}
	push_a_done(&(*info));
}
