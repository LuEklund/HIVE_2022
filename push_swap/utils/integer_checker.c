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

static void	add_largest(t_stack **curr, t_stack **new)
{
	if ((*curr)->larger == NULL || (*new)->value < (*curr)->larger->value)
		(*curr)->larger = *new;
	else
		return ;
}

int	fixer_checker(t_stack *curr, t_stack *new, int value)
{
	if (curr->value == value)
	{
		free(new);
		new = NULL;
		return (0);
	}
	if (value > curr->value)
		add_largest(&curr, &new);
	if (value < curr->value)
		add_largest(&new, &curr);
	return (1);
}

t_stack	*init_new_node(t_info **info, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->larger = NULL;
	(*info)->a_size++;
	if (!(*info)->smallest || (value < (*info)->smallest->value))
		(*info)->smallest = new;
	return (new);
}

static int	add_list(t_info **info, int value)
{
	t_stack	*curr;
	t_stack	*new;

	new = init_new_node(info, value);
	if (!new)
		return (0);
	curr = (*info)->a;
	if (curr == NULL)
		(*info)->a = new;
	else
	{
		while (curr->next != NULL)
		{
			if (!fixer_checker(curr, new, value))
				return (0);
			curr = curr->next;
		}
		if (!fixer_checker(curr, new, value))
			return (0);
		(*info)->a_last = new;
		curr->next = new;
	}
	return (1);
}

int	integer_checker(const char *nptr, t_info **info, int i)
{
	int long	value;
	int			isnegative;

	isnegative = 1;
	value = 0;
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
			return (error_message());
		value = value * 10 + nptr[i] - '0';
		i++;
		if (value > 2147483647 || (value * isnegative < -2147483648))
			return (error_message());
	}
	if (!add_list((info), (value * isnegative)))
		return (error_message());
	return (1);
}
