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

t_info	*t_info_init(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->a_size = 0;
	info->b_size = 0;
	info->moves = 0;
	info->mid_mid_dev = 0;
	info->smallest = NULL;
	info->mid = NULL;
	info->mid_mid = NULL;
	info->first_mid_mid = NULL;
	info->a = NULL;
	info->b = NULL;
	return (info);
}

int	checker(int argc, int i, t_info	*info, char **argv)
{
	while (argc > i)
	{
		if (!integer_checker(argv[i], &info, 0))
			return (0);
		i++;
	}
	return (1);
}

int	arg_check(int argc, int valid, t_info *info, char **argv)
{
	char	**str_2d;
	int		i;

	i = 1;
	if (argc == 2)
	{
		str_2d = ft_split(argv[1], ' ');
		argc = 0;
		while (str_2d[argc] != NULL)
			argc++;
		valid = checker(argc, 0, info, str_2d);
		argc = 0;
		free_args(str_2d);
	}
	else
	{
		while (argc > i)
		{
			if (!integer_checker(argv[i], &info, 0))
				return (0);
			i++;
		}
	}
	return (valid);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		valid;

	valid = 1;
	info = t_info_init();
	if (!info)
		return (0);
	if (argc > 1)
	{
		valid = arg_check(argc, valid, info, argv);
		if (valid)
		{
			if (info->a_size > 160)
				info->mid_mid_dev = 8;
			else
				info->mid_mid_dev = 4;
			if (info->a_size && info->a_size != 1)
				start_sort(&info);
		}
	}
	free_stack(&info->a);
	free_stack(&info->b);
	free(info);
	return (0);
}
