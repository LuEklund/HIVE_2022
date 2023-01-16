/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:32:36 by leklund           #+#    #+#             */
/*   Updated: 2023/01/15 14:32:39 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <signal.h>

//REMOVE INCLUDE
# include <stdio.h>

typedef struct s_info
{
	char	*str;
	char	temp_c;
	int		index;
}				t_info;

#endif
