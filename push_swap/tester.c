/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:08:49 by leklund           #+#    #+#             */
/*   Updated: 2023/01/02 14:08:52 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "includes/push_swap.h"

void st_info(t_info **info)
{
	ft_printf("------=====================[NEW-INFO]=====================------\n");
	ft_printf("a_size[%i] and b_size[%i]\n", (*info)->a_size, (*info)->b_size);
	ft_printf("middle value is[%i] and mid_mid value is[%i]\n", (*info)->mid->value, (*info)->mid_mid->value);
	ft_printf("last value in stack a [%i]\n", (*info)->a_last->value);
	ft_printf("------=====================[NEW-INFO]=====================------\n");
}

// static void	print_order_list(t_stack **a_stack)
// {
// 	t_stack	*curr;

// 	curr = *a_stack;
// 	if (curr == NULL)
// 		return ;
// 	else
// 	{
// 		while (curr->next != NULL)
// 		{
// 			if(curr->larger != NULL)
// 				ft_printf("VALUE[%i] NEEDS VALUE[%i] after it.\n", curr->value, curr->larger->value);
// 			curr = curr->next;
// 		}
// 		if(curr->larger != NULL)
// 				ft_printf("VALUE[%i] NEEDS VALUE[%i] after it.\n", curr->value, curr->larger->value);
		
// 	}
// }

void	loop(t_info **info, char c, char *s)
{
	t_stack	*tmp;
	t_stack	**stack;

	if (c == 'a')
		stack = &(*info)->a;
	else
		stack = &(*info)->b;
	tmp = *stack;
	ft_printf("-----=[%s]=-----\n", s);
	if (!tmp)
	{
		ft_printf("STACK IS NULL\n", s);
		return ;
	}
	while (tmp->next != NULL)
	{
		ft_printf("%s [%i]", s, tmp->value);
		if (tmp->value < (*info)->mid_mid->value)
			ft_printf("[x]\n");
		else
			ft_printf("[ ]\n");
		tmp = tmp->next;
	}
	ft_printf("%s [%i]", s, tmp->value);
	if (tmp->value < (*info)->mid_mid->value)
		ft_printf("[x]\n");
	else
		ft_printf("[ ]\n");
}