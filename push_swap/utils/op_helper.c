/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:51:01 by leklund           #+#    #+#             */
/*   Updated: 2023/01/06 17:51:02 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

void	rotate1(t_info **info, char c)
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
}

void	rotate_r(t_info **info)
{
	ft_printf("rr\n");
	rotate1(info, 'a');
	rotate1(info, 'b');
}
