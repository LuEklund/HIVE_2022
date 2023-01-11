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
	t_stack	*first_mid_mid;
	t_stack	*a_last;
	t_stack	*b_last;
	int		steps;
	int		a_size;
	int		b_size;
	int		moves;
	int		mid_mid_dev;
}				t_info;

int		integer_checker(const char *nptr, t_info **info, int i);

void	swap(t_info **info, char c);
void	push(t_info **info, char c);
void	rotate(t_info **info, char c);
void	reverse_rotate(t_info **info, char c);

void	rotate_r(t_info **info);
t_stack	**head_helper(t_info **info, char c);
void	push_helper(t_info **info, char c);

int		error_message(void);

void	start_sort(t_info **info);

void	free_stack(t_stack **stack);

int		optimmal_path_is_up_a(t_info **info);

void	put_in_b(t_info **info);

int		in_order(t_stack **stack);

void	start_pushing_a(t_info **info);

void	free_args(char **str_2d);

void	find_mid(t_info **info);
#endif