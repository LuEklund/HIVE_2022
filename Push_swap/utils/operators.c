/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:21:16 by leklund           #+#    #+#             */
/*   Updated: 2022/12/29 13:21:18 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../ft_printf/ft_printf.h"
// ft_printf("New [%i]\n", (*stack)->next->value);

void	loop(t_stack **stack, char *s)
{
	t_stack	*tmp;

	tmp = *stack;
	ft_printf("-----=[%s]=-----\n", s);
	if (!tmp)
	{
		ft_printf("STACK IS NULL\n", s);
		return ;
	}
	while (tmp->next != NULL)
	{
		ft_printf("%s [%i]\n", s, tmp->value);
		tmp = tmp->next;
	}
	ft_printf("%s [%i]\n", s, tmp->value);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*seccond;
	t_stack	*third;

	if (!(*stack) || !(*stack)->next)
	{
		ft_printf("error at swap\n");
		return ;
	}
	first = *stack;
	seccond = first->next;
	third = seccond->next;
	*stack = seccond;
	seccond->next = first;
	first->next = third;
}

void	push(t_stack **stack_to_take_from, t_stack **stack_to_put_on)
{
	t_stack	*first_take;

	if (!(*stack_to_take_from))
	{
		ft_printf("error at push\n");
		return ;
	}
	first_take = *stack_to_take_from;
	*stack_to_take_from = first_take->next;
	first_take->next = *stack_to_put_on;
	*stack_to_put_on = first_take;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*curr;

	first = *stack;
	if (!first || !first->next)
	{
		ft_printf("error at rotate\n");
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	*stack = first->next;
	first->next = NULL;
	curr->next = first;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*curr;

	curr = *stack;
	if (!curr || !curr->next)
	{
		ft_printf("error at reverse_rotate\n");
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->next == NULL)
			last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	last = curr;
	last->next = *stack;
	*stack = last;
}