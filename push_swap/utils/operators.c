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

void	swap(t_info **info, char c)
{
	(*info)->moves++;
	t_stack	**stack;
	t_stack	*first;
	t_stack	*seccond;
	t_stack	*third;

	if (c == 'a')
		stack = &(*info)->a;
	else
		stack = &(*info)->b;
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
	if (!third && c == 'a')
		(*info)->a_last = first;
	else if (!third && c == 'a')
		(*info)->b_last = first;
}

void	push(t_info **info, char c)
{
	(*info)->moves++;
	t_stack	*first_take;
	t_stack	**stack_to_take_from;
	t_stack	**stack_to_put_on;

	if (c == 'a')
	{
		stack_to_take_from = &(*info)->b;
		stack_to_put_on = &(*info)->a;
	}
	else
	{
		stack_to_take_from = &(*info)->a;
		stack_to_put_on = &(*info)->b;
	}
	if (!(*stack_to_take_from))
	{
		ft_printf("error at push\n");
		return ;
	}
	first_take = *stack_to_take_from;
	*stack_to_take_from = first_take->next;
	first_take->next = *stack_to_put_on;
	if (!*stack_to_put_on && c == 'a')
		(*info)->a_last = first_take;
	else if (!*stack_to_put_on && c == 'b')
		(*info)->b_last = first_take;
	*stack_to_put_on = first_take;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_info **info, char c)
{
	(*info)->moves++;
	t_stack	*first;
	t_stack	*curr;
	t_stack	**head;

	if (c == 'a')
		head = &(*info)->a;
	else
		head = &(*info)->b;
	first = *head;
	if (!first || !first->next)
	{
		ft_printf("error at rotate\n");
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	*head = first->next;
	first->next = NULL;
	curr->next = first;
	if (c == 'a')
		(*info)->a_last = first;
	else
		(*info)->b_last = first;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_info **info, char c)
{
	(*info)->moves++;
	t_stack	*last;
	t_stack	*curr;
	t_stack	*first;
	t_stack	**head;

	if (c == 'a')
		head = &(*info)->a;
	else
		head = &(*info)->b;
	curr = *head;
	first = *head;
	last = NULL;
	if (!curr || !curr->next)
	{
		ft_printf("error at reverse_rotate [%c]\n", c);
		return ;
	}
	while (curr->next != NULL)
	{
		if (!last && curr->next->next == NULL)
			last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	if (c == 'a')
		(*info)->a_last = last;
	else
		(*info)->b_last = last;
	curr->next = first;
	*head = curr;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

// void	do_op(t_stack **stack_from, t_stack **stack_to, char *name)
// {
// 	(void) name;
// 	if (!ft_strncmp(name, "Push", 4))
// 		push(stack_from, stack_to);
// 	// if (!ft_strncmp(name, "Rotate", 6))
// 	// 	rotate();
// }