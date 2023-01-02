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