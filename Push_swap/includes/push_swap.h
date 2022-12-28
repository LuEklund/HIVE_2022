/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:01:21 by leklund           #+#    #+#             */
/*   Updated: 2022/12/28 15:01:24 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

//REMOVED INCLUDE!!!!!
# include <stdio.h>
	// if (curr == NULL)
	// {
	// 	printf("once\n");
	// 	*a_stack = new;
	// }
	// else
	// {
	// printf("curr[%i], want to add[%i]\n", curr->value, value);


typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}				t_stacks;

int	integer_checker(const char *nptr, t_stack **a_stack);
#endif

