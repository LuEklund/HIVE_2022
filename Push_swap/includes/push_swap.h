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

typedef struct s_stack
{
	int				value;
	int				*larger;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}				t_stacks;

int		integer_checker(const char *nptr, t_stack **a_stack);
void	swap(t_stack **stack);
void	push(t_stack **stack_to_take_from, t_stack **stack_to_put_on);
void	loop(t_stack **stack, char *s);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
int		error_message(char *s);
// void	free_stack(t_stack **stack);
#endif

