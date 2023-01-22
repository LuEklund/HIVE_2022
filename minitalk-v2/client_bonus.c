/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:34 by leklund           #+#    #+#             */
/*   Updated: 2023/01/18 17:27:37 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/client_bonus.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message recived!\n");
	else
	{
		ft_printf("Message failed!\n");
		exit (0);
	}
}

int	send_char_to_server(int pid, unsigned char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(200);
	}
	return (1);
}

int	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!send_char_to_server(pid, str[i]))
		{
			ft_printf("Message failed!\n");
			return (0);
		}
		i++;
	}
	send_char_to_server(pid, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Client Pid[%i]\n", getpid());
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid && ft_strlen(argv[2]))
			send_string(pid, argv[2]);
	}
	return (0);
}
