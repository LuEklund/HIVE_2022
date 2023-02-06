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

void	sleeping_death(t_philo *philo, int times_ms)
{
	int	time;

	time = get_time_diff(philo);
	// printf("P[%d]wants to sleep for %dms\n", philo->nbr, times_ms);
	times_ms = times_ms + time;
	// printf("P[%d] want to sleep for[%d]\n", philo->nbr, times_ms - time);
	while (times_ms > time)
	{
		time = get_time_diff(philo);
		if (0 >= philo->info->die - (time - philo->last_ate))
		{
			printf("%d %i died - LAST[%d]\n", time, philo->nbr, philo->last_ate);
			philo->info->valid = 0;
			break ;
		}
		usleep(100);
	}
	return ;
}

int	sleeping(t_philo *philo)
{
	int				time;

	
	philo->fork_taken = 0;
	philo->next->fork_taken = 0;
	philo->eaten += 1;
	time = get_time_diff(philo);
	printf("%d %i is sleeping\n", time, philo->nbr);
	sleeping_death(philo, philo->info->sleep);
	return (1);
}

int	eat(t_philo *philo)
{
	int				time;

	time = get_time_diff(philo);
	printf("%d %i is eating\n", time, philo->nbr);
	philo->last_ate = time;
	sleeping_death(philo, philo->info->eat);
	sleeping(philo);
	return (1);
}

int	can_grab_fork(t_philo *philo)
{
	if (!philo->fork_taken)
	{
		philo->fork_taken = 1;
		return (1);
	}
	else
		return (0);
}