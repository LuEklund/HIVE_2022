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
	struct s_stack	*larger;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*smallest;
	t_stack	*mid;
	t_stack	*mid_mid;
	int		orig_size;
	int		a_size;
	int		b_size;
	int		moves;
}				t_info;

int		integer_checker(const char *nptr, t_info **info);
void	do_op(t_stack **stack_from, t_stack **stack_to, char *name);
void	swap(t_stack **stack);
void	push(t_info **info, char c);
// void	loop(t_stack **stack, char *s);
void	rotate(t_info **info, char c);
void	reverse_rotate(t_info **info, char c);
int		error_message(char *s);
void	start_sort(t_info **info);
void	free_stack(t_stack **stack);
void	info(t_info **info);
int		opimmal_path_is_up(t_info **info);


//TESTER INCLUDES REMOVE AND REMOVE IT FROM MAKEFILE ASWELL<------!!!!! OBS
void	find_mid(t_info **info);
// static void	print_order_list(t_stack **a_stack);
void	loop(t_stack **stack, char *s);
#endif

// ft_printf("Smallest value[%i].\nAnd stack size is[%i]\n", (*info)->smallest->value, (*info)->a_size);
// ft_printf("mid steps[%i] Middle value is [%i] orig_size[%i].\n", steps, (*info)->mid->value, (*info)->orig_size);