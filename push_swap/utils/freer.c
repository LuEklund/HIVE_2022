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
	if (!*stack)
		return ;
	if ((*stack)->next)
		free_stack(&(*stack)->next);
	free(*stack);
	stack = NULL;
}

void	free_args(char **str_2d)
{
	int	argc;

	argc = 0;
	while (str_2d[argc] != NULL)
	{
		free(str_2d[argc]);
		argc++;
	}
	free(str_2d[argc]);
	free(str_2d);
}
