/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_client_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:49:21 by leklund           #+#    #+#             */
/*   Updated: 2023/01/20 09:49:22 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/server_bonus.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

// t_info	*remove_node(t_info *start, t_info *curr_client, int pid)
// {

// }

t_info	*new_client(t_info *start, int pid)
{
	ft_printf("new CLIENT\n");
	start = malloc(sizeof(t_info));
	start->client_pid = pid;
	start->next = NULL;
	start->index = 0;
	start->str = NULL;
	start->temp_c = 0;
	return (start);
}

t_info	*find_client(t_info *start, int pid)
{
	if (!start)
		return (new_client(start, pid));
	while (start->next != NULL)
	{
		if (start->client_pid == pid)
			return (start);
		start = start->next;
	}
	if (start->client_pid == pid)
		return (start);
	else
		start->next = new_client(start, pid);
	return (start->next);
}
