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

int	in_order(t_info **info, char c)
{
	t_stack	*curr;

	if (c == 'a')
	{
		curr = (*info)->a;
		while (curr)
		{
			if (curr->next == curr->larger)
				curr = curr->next;
			else if (curr->larger == NULL)
			{
				if (in_order(&curr->next, 'a'))
					return (2);
				else
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}