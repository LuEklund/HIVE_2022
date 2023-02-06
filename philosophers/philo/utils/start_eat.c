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


int	can_wait(t_philo *philo)
{
	int		time;

	time = get_time_diff(philo);
	time = philo->info->die - (time - philo->last_ate);
	// printf("P[%d]: time until Death[%d] (can_wait)\n",philo->nbr, time);
	if (time > 10)
	{
		// printf("P[%d]: sleep time [%d]ms (can_wait)\n",philo->nbr, time/2);
		return (time / 2);
	}
	return (0);

}

int	try_eating( t_philo *first, t_philo *seccond)
{
	int can_eat;

	pthread_mutex_lock(&first->mutex);
	can_eat = can_grab_fork(first);
	pthread_mutex_unlock(&first->mutex);
	pthread_mutex_lock(&seccond->mutex);
	if (can_eat)
	{
		if (can_grab_fork(seccond))
			can_eat = 2;
		else
		{
			can_eat = 0;
			first->fork_taken = 0;
		}
	}
	else
		can_eat = 0;
	pthread_mutex_unlock(&seccond->mutex);
	return (can_eat);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		can_eat;
	int		time;
	struct timeval	tv;


	philo = arg;
	can_eat = 0;
	while (!philo->info->valid)
		;
	gettimeofday(&tv, NULL);
	philo->info->start_time_ms = tv.tv_usec / 1000;
	philo->info->start_time_sec = tv.tv_sec;
	// if (!(philo->nbr % 2))
		// sleeping_death(philo, 3);
	while (philo->info->valid)
	{
		if (philo->nbr % 2)
			can_eat = try_eating(philo, philo->next);
		else
			can_eat = try_eating(philo->next, philo);
		if (can_eat)
		{
			eat(philo);
			philo->say_think = 1;
		}
		if (philo->say_think)
		{
			philo->say_think = 0;
			time = get_time_diff(philo);
			printf("%d %i is thinking\n", time, philo->nbr);
			// sleeping_death(philo, 1);
			// printf("P[%d] die_time[%i], last_ate[%d], time[%i], TTD[%d]\n", philo->nbr, philo->info->die, philo->last_ate, time, philo->info->die - (time - philo->last_ate));
			sleeping_death(philo, can_wait(philo));
		}
		else
		{
			time = get_time_diff(philo);
			if (0 >= philo->info->die - (time - philo->last_ate))
			{
				printf("%d %i died - LAST[%d]\n", time, philo->nbr, philo->last_ate);
				// printf("P[%d] die_time[%i], last_ate[%d], time[%i]\n", philo->nbr, philo->info->die, philo->last_ate, time);
				philo->info->valid = 0;
			}
		}
	}
	return (NULL);
}

void	start_eating(t_philo *philo)
{
	t_philo			*curr;
	int				amount;

	amount = philo->info->philo_amount;
	curr = philo;
	int_mutexs(amount, philo);
	philo->info->valid = 0;
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
	check_if_valid_game(philo);
	close_threads(amount, philo);
}