/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:44:44 by leklund           #+#    #+#             */
/*   Updated: 2023/01/23 18:44:47 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	get_time_diff(t_philo *philo)
{
	struct timeval	tv;
	int				time;
	int				sec;
	int				ms;

	gettimeofday(&tv, NULL);
	sec = (tv.tv_sec - philo->info->start_time_sec) * 1000;
	ms = (tv.tv_usec / 1000) - philo->info->start_time_ms;
	time = sec + ms;
	return (time);
}

int	sleeping(t_philo *philo)
{
	int				time;

	time = get_time_diff(philo);
	printf("%d %i is sleeping\n", time, philo->nbr);
	philo->fork_taken = 0;
	philo->next->fork_taken = 0;
	philo->eaten += 1;
	// if
	usleep(philo->info->sleep * 1000);
	return (1);
}

int	eat(t_philo *philo)
{
	int				time;

	time = get_time_diff(philo);
	printf("%d %i is eating\n", time, philo->nbr);
	usleep(philo->info->eat * 1000);
	time = get_time_diff(philo);
	philo->last_ate = time;
	sleeping(philo);
	return (1);
}

int	can_grab_froks(t_philo *philo)
{
	int				time;

	if (!philo->fork_taken && !philo->next->fork_taken)
	{
		philo->fork_taken = 1;
		time = get_time_diff(philo);
		printf("%d %i has taken a fork\n", time, philo->nbr);
		philo->next->fork_taken = 1;
		time = get_time_diff(philo);
		printf("%d %i has taken a fork\n", time, philo->nbr);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	think(t_philo *philo)
{
	int	time;

	time = get_time_diff(philo);
	printf("%d %i is thinking\n", time, philo->nbr);
	return (1);
}
