/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:43:08 by leklund           #+#    #+#             */
/*   Updated: 2023/01/22 11:43:10 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/philo.h"

// pthread_mutex_t mutex;


int	nbr_conv(const char *nptr)
{
	long int	value;
	int			i;

	value = 0;
	i = 0;
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0'))
	{
		if (!(nptr[i] > 47 && nptr[i] < 58))
			return (-1);
		value = value * 10 + nptr[i] - '0';
		i++;
		if (value < 0)
			return (-1);
	}
	return ((int) value);
}

int	make_values(int argc, char **argv, t_info *info)
{
	if (argc == 6)
	{
		info->must_eat = nbr_conv(argv[5]);
		if (info->must_eat == -1)
			return (0);
	}
	else
		info->must_eat = -1;
	info->philo_amount = nbr_conv(argv[1]);
	info->die = nbr_conv(argv[2]);
	info->eat = nbr_conv(argv[3]);
	info->sleep = nbr_conv(argv[4]);
	if (info->philo_amount == -1 || info->die == -1 || info->eat == -1
		|| info->sleep == -1 || !info->philo_amount)
		return (0);
	return (1);
}

int	create_philosophers(t_info *info, t_philo **philo)
{
	int		amount;
	int		i;
	t_philo	*latest;
	t_philo	*new;

	i = 0;
	amount = info->philo_amount;
	while (amount > i)
	{
		i++;
		new = malloc(sizeof(t_philo));
		if (!new)
			return (0);
		new->nbr = i;
		new->fork_taken = 0;
		new->eaten = 0;
		new->last_ate = 0;
		new->say_think = 0;
		new->next = NULL;
		new->info = info;
		if (!(*philo))
			*philo = new;
		else
			latest->next = new;
		latest = new;
		latest->next = *philo;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info			*info;
	t_philo			*philo;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		if (make_values(argc, argv, info) && create_philosophers(info, &philo))
		{
			info->valid = 0;
			start_eating(philo);
		}
	}
	free_list(philo);
	free(info);
	return (0);
}
