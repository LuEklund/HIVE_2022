/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:34:55 by leklund           #+#    #+#             */
/*   Updated: 2023/01/30 15:34:58 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	all_have_eaten(t_philo *philo)
{
	int		amount;
	t_philo	*curr;

	amount = philo->info->philo_amount;
	curr = philo;
	while (amount)
	{
		if (curr->eaten >= curr->info->must_eat)
			curr = curr->next;
		else
			return (0);
		amount--;
	}
	return (1);
}

int	check_if_valid_game(t_philo *philo)
{
	philo->info->valid = 1;
	if (philo->info->must_eat != -1)
	{
		while (philo->info->valid)
		{
			if (all_have_eaten(philo))
			{
				philo->info->valid = 0;
				printf("all ate\n");
			}
		}
	}
	return (1);
}

int	int_mutexs(int amount, t_philo *philo)
{
	t_philo			*curr;

	curr = philo;
	while (amount)
	{
		pthread_mutex_init(&curr->mutex, NULL);
		curr = curr->next;
		amount--;
	}
	return (1);
}

int	close_threads(int amount, t_philo *philo)
{
	t_philo			*curr;

	curr = philo;
	while (amount)
	{
		if (pthread_join(curr->th, (void **) NULL) != 0)
		{
			printf("JOIN ERROR");
		}
		pthread_mutex_destroy(&philo->mutex);
		curr = curr->next;
		amount--;
	}
	return (1);
}
