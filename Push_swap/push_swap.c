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

void	find_mid(t_stacks **stacks)
{
	t_stack	*mid;
	int		steps;

	steps = (*stacks)->a_size / 2;
	mid = (*stacks)->smallest;
	while (steps > 0)
	{
		mid = mid->larger;
		steps--;
	}
	ft_printf("Middle value is [%i].\n", mid->value);
}

static void	print_order_list(t_stack **a_stack)
{
	t_stack	*curr;

	curr = *a_stack;
	if (curr == NULL)
		return ;
	else
	{
		while (curr->next != NULL)
		{
			if(curr->larger != NULL)
				ft_printf("VALUE[%i] NEEDS VALUE[%i] after it.\n", curr->value, curr->larger->value);
			curr = curr->next;
		}
		if(curr->larger != NULL)
				ft_printf("VALUE[%i] NEEDS VALUE[%i] after it.\n", curr->value, curr->larger->value);
		
	}

}


int	main(int argc, char **argv)
{
	int			i;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->a_size = 0;
	// stacks->smallest = malloc(sizeof(t_stack));
	stacks->smallest = NULL;
	// stacks->a = malloc(sizeof(t_stack));
	stacks->a = NULL;
	// stacks->b = malloc(sizeof(t_stack));
	stacks->b = NULL;
	i = 1;
	if (argc > 1)
	{
		while (argc > i)
		{
			if (integer_checker(argv[i], &stacks))
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
		// loop(&stacks->a, "stack_A before");
		// loop(&stacks->b, "stack_B before");
		// push(&stacks->a, &stacks->b);
		// push(&stacks->a, &stacks->b);
		// push(&stacks->a, &stacks->b);
		// push(&stacks->a, &stacks->b);
		// loop(&stacks->a, "stack_A after");
		// loop(&stacks->b, "stack_B after");

		// push(&stacks->a, &stacks->b);

		print_order_list(&stacks->a);
		ft_printf("Smallest value[%i].\n And stack size is[%i]\n", stacks->smallest->value, stacks->a_size);
		find_mid(&stacks);
	}
	return (0);
}
