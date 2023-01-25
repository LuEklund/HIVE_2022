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

// void	death_loop(t_philo *philo, int times_ms)
// {
// 	int	time;

// 	while (times_ms >= 5)
// 	{
// 		printf("wants to sleep for %dms\n", times_ms);
// 		printf("time until Death_loop[%d]\n", philo->info->die - (time - philo->last_ate));
// 		time = get_time_diff(philo);
// 		if (philo->info->die <= time - philo->last_ate)
// 		{
// 			printf("%d %i died\n", time, philo->nbr);
// 			philo->info->valid = 0;
// 			return ;
// 		}
// 		times_ms -= 5;
// 		usleep(5000);
// 	}
// 	usleep(times_ms * 1000);
// }

int	sleeping(t_philo *philo)
{
	int				time;

	time = get_time_diff(philo);
	printf("%d %i is sleeping\n", time, philo->nbr);
	philo->fork_taken = 0;
	philo->next->fork_taken = 0;
	philo->eaten += 1;
	usleep(philo->info->sleep * 1000);
	return (1);
}

int	eat(t_philo *philo)
{
	int				time;

	time = get_time_diff(philo);
	philo->last_ate = time;
	printf("%d %i is eating\n", time, philo->nbr);
	usleep(philo->info->eat * 1000);
	sleeping(philo);
	return (1);
}

int	can_grab_froks(t_philo *philo)
{
	int				time;

	if (!philo->fork_taken && !philo->next->fork_taken && (philo != philo->next))
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

// int	think(t_philo *philo)
// {
// 	int	time;

// 	time = get_time_diff(philo);
// 	printf("%d %i is thinking\n", time, philo->nbr);
// 	return (1);
// }
