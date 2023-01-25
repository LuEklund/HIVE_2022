/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:37:13 by leklund           #+#    #+#             */
/*   Updated: 2023/01/23 18:37:14 by leklund          ###   ########.fr       */
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

int	have_time(t_philo *philo)
{
	int		time;

	time = get_time_diff(philo);
	time = philo->info->die - (time - philo->last_ate);
	if (10 < time)
		return (time);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		can_eat;
	int		time;

	philo = arg;
	can_eat = 2;
	while (philo->info->valid)
	{
		if (can_eat == 1)
		{
			// usleep(have_time(philo) * 1000);
		}
		can_eat = 0;
		pthread_mutex_lock(&philo->mutex);
		if (philo->next != philo)
			pthread_mutex_lock(&philo->next->mutex);
		can_eat = can_grab_froks(arg);
		pthread_mutex_unlock(&philo->mutex);
		if (philo->next != philo)
			pthread_mutex_unlock(&philo->next->mutex);
		time = get_time_diff(philo);
		if (philo->info->die <= time - philo->last_ate)
		{
			printf("die_time[%i], last_ate[%d], time[%i]\n", philo->info->die, philo->last_ate, time);
			philo->info->valid = 0;
		}
		else
		{
			if (can_eat)
			{
				eat(arg);
				philo->say_think = 1;
			}
			else if	(philo->say_think)
			{
				time = get_time_diff(philo);
				printf("%d %i is thinking\n", time, philo->nbr);
				philo->say_think = 0;
				usleep(philo->info->die - (philo->info->die/2));
			}
		}
	}
	return (NULL);
}

void	start_eating(t_philo *philo)
{
	t_philo			*curr;
	int				amount;
	struct timeval	tv;

	amount = philo->info->philo_amount;
	curr = philo;
	while (amount)
	{
		pthread_mutex_init(&curr->mutex, NULL);
		curr = curr->next;
		amount--;
	}
	amount = philo->info->philo_amount;
	curr = philo;
	gettimeofday(&tv, NULL);
	philo->info->start_time_ms = tv.tv_usec / 1000;
	philo->info->start_time_sec = tv.tv_sec;
	while (amount)
	{
		if (pthread_create(&curr->th, NULL, &routine, curr) != 0)
		{
			printf("CREATE ERROR");
		}
		curr = curr->next;
		amount--;
	}
	amount = philo->info->philo_amount;
	curr = philo;
	if (curr->info->must_eat != -1)
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
}