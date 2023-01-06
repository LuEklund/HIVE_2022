/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:13:44 by leklund           #+#    #+#             */
/*   Updated: 2022/12/30 12:13:45 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../ft_printf/ft_printf.h"

// int		semi_order(t_stack **stack, char c)
// {
// 	t_stack	*curr;

// 	curr = *stack;
// 	while()
// }

int	in_order(t_stack **stack, t_info **info, char c)
{
	t_stack	*curr;

	curr = *stack;
	if (!curr)
		return (1);
	if (c == 'A')
	{
		while (curr->next)
		{
			if (curr->next == curr->larger)
				curr = curr->next;
			else if (curr->larger == NULL)
			{
				if (in_order(&curr->next, &(*info), 'A'))
					return (2);
				else
					return (0);
			}
			else
				return (0);
		}
	}
	else if (c == 'B')
	{
		while (curr->next)
		{
			if (curr == curr->next->larger)
				curr = curr->next;
			else if (curr->next == (*info)->smallest)
			{
				if (in_order(&curr->next, &(*info), 'B'))
					return (2);
				else
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

int	shift_up_a(t_info **info)
{
	t_stack	*curr;
	int		i;
	int		first_pos;
	int		last_pos;

	curr = (*info)->a->next;
	i = 1;
	first_pos = 0;
	last_pos = 0;
	while (curr->next)
	{
		if (curr->value < (*info)->mid->value)
		{
			if (!first_pos)
				first_pos = i;
			last_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (curr->value < (*info)->mid->value)
	{
		if (!first_pos)
			first_pos = i;
		last_pos = i;
	}
	// mid = size / 2;
	// ft_printf("FIRST[%i]\nLAST[%i]\n",first_pos, last_pos,);
	// ft_printf("top[%i] bot[%i]\n",first_pos, size - last_pos);
	if (!first_pos)
		return (0);
	if (first_pos <= (*info)->a_size - last_pos)
		return (1);
	else
		return (0);
}

// int	if_connected()
// {
// 	//dont wanna swap if
// 	//the (last or previuos) is linked with first one
// 	//OR the second one adn third one are linked
// }

int	want_swap(t_stack **stack, char c)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	if (c == 'A')
	{
		if ((*stack)->value > (*stack)->next->value)
			return (1);
	}
	else if (c == 'B')
	{
		if ((*stack)->value < (*stack)->next->value)
			return (1);
	}
	return (0);
}

void	push_a_done(t_info **info)
{
	t_stack	*curr;

	curr = (*info)->b;
	if (!curr)
		return ;
	while (curr->next)
	{
		(*info)->moves++;
		ft_printf("pa\n");
		curr = curr->next;
		push(&(*info)->b, &(*info)->a);
		
	}
	(*info)->moves++;
	ft_printf("pa\n");
	push(&(*info)->b, &(*info)->a);
}

// void	if_connected(t_info **info)
// {
	
// }

void	ss(t_info **info)
{
	ft_printf("ss\n");
	(*info)->moves++;
	swap(&(*info)->a);
	swap(&(*info)->b);
}

void	find_next_samllest(t_info **info)
{
	int	a_want_swap;
	int	b_want_swap;
	

	if (shift_up_a(&(*info)))
	{
		while ((*info)->a->value >= (*info)->mid->value)
		{
			a_want_swap = want_swap(&(*info)->a, 'A');
			b_want_swap = want_swap(&(*info)->b, 'B');
			if (a_want_swap && b_want_swap && (*info)->a->larger != NULL)
				ss(info);
			else if(b_want_swap)
			{
				(*info)->moves++;
				ft_printf("rr\n");
				rotate(&(*info)->a);
				rotate(&(*info)->b);
			}
			else
			{
				(*info)->moves++;
				ft_printf("ra\n");
				rotate(&(*info)->a);
			}
		}
	}
	else
	{
		while ((*info)->a->value >= (*info)->mid->value)
		{
			a_want_swap = want_swap(&(*info)->a, 'A');
			b_want_swap = want_swap(&(*info)->b, 'B');
			if (a_want_swap && b_want_swap && (*info)->a->larger != NULL)
				ss(info);
			else if(b_want_swap)
			{
				(*info)->moves++;
				ft_printf("rrr\n");
				reverse_rotate(&(*info)->a);
				reverse_rotate(&(*info)->b);
			}
			else
			{
				(*info)->moves++;
				ft_printf("rra\n");
				reverse_rotate(&(*info)->a);
			}
		}
	}
}

int fix_a(t_info **info)
{
	//find first accourens_of not alligned number, (should not be smallest and largest switch)
	t_stack	*stack_a;
	int		first;
	int		last;
	int		i;

	last = 0;
	first = 0;
	i = 0;
	stack_a = (*info)->a;
	while (stack_a->next)
	{
		if (stack_a->next->larger != NULL && want_swap(&stack_a, 'A'))
		{
			if (!first)
				first = last;
			last = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (!first)
		return (0);
	if (first <= (*info)->a_size - last)
		return (1);
	else
		return (0);
}

int	find_largest_in_b(t_info **info)
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	int		i;

	// ft_printf("B_SIZE[%i]\n", (*info)->b_size);
	i = 0;
	stack_b = (*info)->b;
	stack_a = (*info)->a;
	while (stack_b->next)
	{
		if (stack_a == stack_b->larger)
			break ;
		i++;
		stack_b = stack_b->next;
	}
	if (i <= (*info)->b_size/2)
		return (1);
	else
		return (0);
}

void solve_b_stack(t_info **info, int status)
{
	if ((*info)->b_size < 2)
		return ;
	// ft_printf("B_SIZE[%i]\n", status);
	while (!status)
	{
		(*info)->moves++;
		if ((*info)->b->larger == (*info)->a)
		{
			(*info)->a_size++;
			(*info)->b_size--;
			ft_printf("pa\n");
			push(&(*info)->b, &(*info)->a);
		}
		else if ((*info)->b->value > (*info)->b->next->value)
		{
			ft_printf("sb\n");
			swap(&(*info)->b);
		}
		else if (find_largest_in_b(&(*info)))
		{
			ft_printf("rb\n");
			rotate(&(*info)->b);
		}
		else
		{
			ft_printf("rrb\n");
			reverse_rotate(&(*info)->b);
		}
		status = in_order(&(*info)->b, &(*info), 'B');
		if (status)
			break;
	}
}

void	solve_a_stack(t_info **info)
{
	t_stack	*stack_a;

	stack_a = (*info)->a;
	if (shift_up_a(&(*info)))
	{
		while (in_order(&(*info)->a, &(*info), 'A') != 1)
		{
			ft_printf("ra\n");
			rotate(&(*info)->a);
		}
	}
	else
	{
		while (in_order(&(*info)->a, &(*info), 'A') != 1)
		{
			ft_printf("rra\n");
			reverse_rotate(&(*info)->a);
		}
	}
}

void	what_to_doer(t_info **info)
{
	int	a_stack_status;
	int	b_stack_status;

	a_stack_status = in_order(&(*info)->a, &(*info), 'A');
	b_stack_status = in_order(&(*info)->b, &(*info), 'B');
	// printf("A_status[%i], B_status[%i]\n",a_stack_status, b_stack_status);
	// ft_printf("curr[%i], middle[%i]\n", (*info)->a->value, (*info)->mid->value);
	while (!a_stack_status)
	{
		// ft_printf("orig_size[%i]. b_size[%i], mid value[%i]\n", (*info)->orig_size, (*info)->b_size, (*info)->mid->value);
		// printf("\n\n============================\n");
		if ((*info)->b_size < (*info)->orig_size / 2)
		{
			// ft_printf("VALID1\n");
			if ((*info)->a->value < (*info)->mid->value)
			{
				// ft_printf("VALID2\n");
				(*info)->a_size--;
				(*info)->b_size++;
				(*info)->moves++;
				ft_printf("pb\n");
				// do_op(&(*info)->a, &(*info)->b, "Push");
				push(&(*info)->a, &(*info)->b);
			}
			else
				find_next_samllest(&(*info));
		}
		else if (want_swap(&(*info)->a, 'A') && want_swap(&(*info)->b, 'B'))
			ss(info);
		else
		{
			if (fix_a(info))
			{
				while ((*info)->a->value < (*info)->a->next->value || (*info)->a->larger == NULL)
				{
					(*info)->moves++;
					if (!b_stack_status && !want_swap(&(*info)->b, 'B'))
					{
						ft_printf("rr\n");
						rotate(&(*info)->a);
						rotate(&(*info)->b);
					}
					else
					{
						ft_printf("ra\n");
						rotate(&(*info)->a);
					}
					b_stack_status = in_order(&(*info)->b, &(*info), 'B');
					a_stack_status = in_order(&(*info)->a, &(*info), 'A');
					if (a_stack_status)
						break ;
				}
			}
			else
			{
				while ((*info)->a->value < (*info)->a->next->value || (*info)->a->larger == NULL)
				{
					(*info)->moves++;
					if (!b_stack_status && !want_swap(&(*info)->b, 'B') )
					{
						ft_printf("rrr\n");
						reverse_rotate(&(*info)->a);
						reverse_rotate(&(*info)->b);
					}
					else
					{
						ft_printf("rra\n");
						reverse_rotate(&(*info)->a);
					}
					b_stack_status = in_order(&(*info)->b, &(*info), 'B');
					a_stack_status = in_order(&(*info)->a, &(*info), 'A');
					if (a_stack_status)
						break ;
				}
			}
			if (want_swap(&(*info)->b, 'B'))
				ss(info);
			else if(want_swap(&(*info)->a, 'A'))
			{
				(*info)->moves++;
				ft_printf("sa\n");
				swap(&(*info)->a);
			}
		}
		// loop(&(*info)->a,"A");
		// loop(&(*info)->b,"B");
		
		a_stack_status = in_order(&(*info)->a, &(*info), 'A');
		b_stack_status = in_order(&(*info)->b, &(*info), 'B');
	}
	if (a_stack_status == 2)
		solve_a_stack(&(*info));
	// ft_printf("B_SIZE[%i], B_ORDER[%i]\n", (*info)->b_size, b_stack_status);
	if(!b_stack_status)
		solve_b_stack(&(*info), b_stack_status);
	push_a_done(&(*info));
}
