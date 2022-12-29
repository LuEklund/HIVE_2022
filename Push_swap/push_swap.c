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
	stacks->b = malloc(sizeof(t_stack));
	stacks->b = NULL;
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
			{
				ft_printf("INVALID\n");
				return (0);
			}
			i++;
		}
		// loop(&stacks->a, "Old");
		// swap(&stacks->a);
		// loop(&stacks->a, "New");
		// loop(&stacks->a, "Old");
		// reverse_rotate(&stacks->a);
		// loop(&stacks->a, "Old");
		// swap(&stacks->a);
		// swap(&stacks->a);
		// swap(&stacks->a);
		// swap(&stacks->a);
		// swap(&stacks->a);
		// loop(&stacks->a, "New");
		// rotate(&stacks->a);
		// loop(&stacks->a, "New");
		// loop(&stacks->a, "Old");
		// swap(&stacks->a);
		// loop(&stacks->a, "New");
		loop(&stacks->a, "stack_A before");
		loop(&stacks->b, "stack_B before");
		push(&stacks->a, &stacks->b);
		push(&stacks->a, &stacks->b);
		push(&stacks->a, &stacks->b);
		push(&stacks->a, &stacks->b);
		loop(&stacks->a, "stack_A after");
		loop(&stacks->b, "stack_B after");

		// push(&stacks->a, &stacks->b);

		
	}
	return (0);
}
