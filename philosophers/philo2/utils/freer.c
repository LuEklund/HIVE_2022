/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:03:43 by leklund           #+#    #+#             */
/*   Updated: 2023/01/23 17:03:46 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	free_list(t_philo *philo)
{
	t_philo	*next;
	int		amount;

	if (!philo)
		return ;
	amount = philo->info->philo_amount;
	while (amount && philo)
	{
		if (philo->next)
			next = philo->next;
		else
			next = NULL;
		free(philo);
		philo = NULL;
		philo = next;
		amount--;
	}
}
