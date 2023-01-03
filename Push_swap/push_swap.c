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

void	find_mid(t_info **info)
{
	t_stack	*mid;
	int		steps;

	ft_printf("Smallest value[%i].\nAnd stack size is[%i]\n", (*info)->smallest->value, (*info)->a_size);
	steps = (*info)->a_size / 2;
	mid = (*info)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	(*info)->mid = mid;
	ft_printf("Middle value is [%i][%i].\n", mid->value, (*info)->mid->value);
}

int	main(int argc, char **argv)
{
	int			i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->a_size = 0;
	info->b_size = 0;
	info->moves = 0;
	// info->smallest = malloc(sizeof(t_stack));
	info->smallest = NULL;
	// info->a = malloc(sizeof(t_stack));
	info->a = NULL;
	// info->b = malloc(sizeof(t_stack));
	info->b = NULL;
	i = 1;
	if (argc > 1)
	{
		while (argc > i)
		{
			if (integer_checker(argv[i], &info))
			{
				ft_printf("VALID\n");
			}
			else
			{
				ft_printf("INVALID\n");
				return (0);
			}
			i++;
		}

		find_mid(&info);
		// loop(&info->a, "stack[A]");
		what_to_doer(&info);
		loop(&info->a, "stack[A]");
		loop(&info->b, "stack[B]");
		ft_printf("MOVES\n--===[%i]===--", info->moves);
	}
	return (0);
}
