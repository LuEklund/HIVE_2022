/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:28:26 by leklund           #+#    #+#             */
/*   Updated: 2023/01/18 17:28:29 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# include <unistd.h>
# include <signal.h>

typedef struct s_info
{
	char			*str;
	char			temp_c;
	int				index;
	int				client_pid;
	struct s_info	*next;
}				t_info;

t_info	*find_client(t_info *start, int pid);

#endif
