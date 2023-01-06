/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:49:06 by leklund           #+#    #+#             */
/*   Updated: 2022/12/28 15:49:08 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../ft_printf/ft_printf.h"

static int	blank_skipper(int i, const char *nptr)
{
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	return (i);
}


// static int	free_return(t_stack **a_stack)
// {

// }
static void	add_largest(t_stack **curr, t_stack **new)
{
	if ((*curr)->larger == NULL || (*new)->value < (*curr)->larger->value)
		(*curr)->larger = *new;
	else
		return ;
	// printf("[SUCCESS]new large value for %i is %i\n", (*curr)->value, (*new)->value);
}

// static void	add_largest_last(t_stack **a_stack, t_stack **new)
// {
// 	t_stack	*curr;

// 	curr = *a_stack;
// 	if (curr == NULL)
// 		return ;
// 	else
// 	{
// 		while (curr->next != NULL)
// 		{
// 			if((*new)->value < curr->value)
// 				add_largest(new, &curr->value);
// 			curr = curr->next;
// 		}
// 	}
// }



static int	add_list(t_info **info, int value)
{
	t_stack	*curr;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	new->larger = NULL;
	(*info)->a_size += 1;
	if (!(*info)->smallest || (value < (*info)->smallest->value))
		(*info)->smallest = new;
	curr = (*info)->a;
	if (curr == NULL)
		(*info)->a = new;
	else
	{
		while (curr->next != NULL)
		{
			if (curr->value == value)
			{
				new = NULL;
				free(new);
				return (0);
			}
			if (value > curr->value)
				add_largest(&curr, &new);
			if (value < curr->value)
				add_largest(&new, &curr);
			curr = curr->next;
		}
		if (curr->value == value)
		{
			new = NULL;
			free(new);
			return (0);
		}
		if (value > curr->value)
			add_largest(&curr, &new);
		if (value < curr->value)
			add_largest(&new, &curr);
		curr->next = new;
		// add_largest_last(a_stack, &new);
	}
	return (1);
}

int	integer_checker(const char *nptr, t_info **info)
{
	int long	value;
	int			isnegative;
	int			i;

	isnegative = 1;
	value = 0;
	i = 0;
	i = blank_skipper(i, nptr);
	if (nptr[i] == '-')
	{
		isnegative = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0'))
	{
		if (nptr[i] < 47 || nptr[i] > 58)
			return (error_message("argument is not a integer"));
		value = value * 10 + nptr[i] - '0';
		i++;
		if (value > 2147483647 || (value * isnegative < -2147483648))
			return (error_message("over INT_MAX or under INT_MIN, Not okay"));
	}
	if (!add_list((info), (value * isnegative)))
		return (error_message("no duplicates please"));
	return (1);
}