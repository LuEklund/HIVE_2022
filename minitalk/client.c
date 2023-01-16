/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:17 by leklund           #+#    #+#             */
/*   Updated: 2023/01/12 16:09:18 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/client.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	send_char_to_server(int pid, unsigned char c)
{
	unsigned char	bit;
	// (void) pid;
	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
			// printf("1\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
			// printf("0\n");
		}
		bit >>= 1;
		usleep(100);
	}
	return (1);
}

int	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char_to_server(pid, str[i]);
		i++;
	}
	send_char_to_server(pid, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("PID = %i", pid);
		send_string(pid, argv[2]);
	}
	return (0);
}