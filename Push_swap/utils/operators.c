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
#include "../libft/libft.h"
// ft_printf("New [%i]\n", (*stack)->next->value);

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
	t_stack	*first;

	curr = *stack;
	first = *stack;
	last = NULL;
	if (!curr || !curr->next)
	{
		ft_printf("error at reverse_rotate\n");
		return ;
	}
	while (curr->next != NULL)
	{
		if (!last && curr->next->next == NULL)
			last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	curr->next = first;
	*stack = curr;
}

void	do_op(t_stack **stack_from, t_stack **stack_to, char *name)
{
	(void) name;
	if (!ft_strncmp(name, "Push", 4))
		push(stack_from, stack_to);
	// if (!ft_strncmp(name, "Rotate", 6))
	// 	rotate();
}