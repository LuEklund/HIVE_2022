/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:00:09 by leklund           #+#    #+#             */
/*   Updated: 2022/12/28 15:00:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "includes/push_swap.h"



int	main(int argc, char **argv)
{
	int			i;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(t_stack));
	stacks->a = NULL;
	// stacks->a->value = 0;
	i = 1;
	if (argc > 1)
	{
		while (argc > i)
		{
			if (integer_checker(argv[i], &stacks->a))
			{
				ft_printf("VALID\n");
			}
			else
				ft_printf("INVALID\n");
			i++;
		}
	}
	return (0);
}
