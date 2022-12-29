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

static int	blank_skipper(int i, const char *nptr)
{
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	return (i);
}

// static int	free_return(t_stack **a_stack)
// {

// }

static int	add_list(t_stack **a_stack, int value)
{
	t_stack	*curr;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	curr = *a_stack;
	if (curr == NULL)
		*a_stack = new;
	else
	{
		while (curr->next != NULL)
		{
			if (curr->value == value)
			{
				new = NULL;
				free(new);
				// free_stack(a_stack);
				return (0);
			}
			curr = curr->next;
		}
		if (curr->value == value)
		{
			new = NULL;
			free(new);
			// free_stack(a_stack);
			return (0);
		}
		curr->next = new;
	}
	return (1);
}

int	integer_checker(const char *nptr, t_stack **a_stack)
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
	if (!add_list(a_stack, (value * isnegative)))
		return (error_message("no duplicates please"));
	return (1);
}