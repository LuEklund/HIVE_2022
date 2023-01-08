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
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->a_size = 0;
	info->b_size = 0;
	info->moves = 0;
	// info->smallest = malloc(sizeof(t_stack));
	info->smallest = NULL;
	info->mid = NULL;
	info->mid_mid = NULL;
	info->first_mid_mid = NULL;
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
				// ft_printf("VALID\n");
			}
			else
			{
				// ft_printf("INVALID\n");
				return (0);
			}
			i++;
		}
		
		// find_mid(&info);
		// loop(&info->a, "STACK A");
		start_sort(&info);
		// loop(&info->a, "STACK A");
		
		// ft_printf("VALID\n");
		// loop(&info->a, "stack[A]");
		// what_to_doer(&info);
		// loop(&info->a, "stack[A]");
		// loop(&info->b, "stack[B]");
		// ft_printf("MOVES\n--===[%i]===--", info->moves);
	}
	free_stack(&info->a);
	free_stack(&info->b);
	free(info);
	return (0);
}
