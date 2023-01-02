/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:45:24 by leklund           #+#    #+#             */
/*   Updated: 2022/12/29 11:45:26 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	if (curr->next)
		free_stack(&curr->next);
	printf("freed [%i]", curr->value);
	stack = NULL;
	free(stack);
}