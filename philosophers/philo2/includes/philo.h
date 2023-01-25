/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:53:31 by leklund           #+#    #+#             */
/*   Updated: 2023/01/22 11:53:33 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	int				philo_amount;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				start_time_ms;
	int				start_time_sec;
	int				valid;
}				t_info;

typedef struct s_philo
{
	pthread_t		th;
	t_info			*info;
	int				fork_taken;
	int				eaten;
	int				say_think;
	int				last_ate;
	pthread_mutex_t	mutex;
	int				nbr;
	struct s_philo	*next;
}				t_philo;

void	free_list(t_philo *philo);
void	start_eating(t_philo *philo);
int		eat(t_philo *philo);
int		think(t_philo *philo);
int		can_grab_froks(t_philo *philo);
// int		died(t_philo *philo);
int		get_time_diff(t_philo *philo);
#endif
