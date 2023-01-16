/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:32 by leklund           #+#    #+#             */
/*   Updated: 2023/01/12 16:09:33 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/server.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

t_info	g_info;

int	string_saver(void)
{
	char	*tmp;

	if (!g_info.temp_c)
		return (1);
	if (!g_info.str)
	{
		g_info.str = malloc(sizeof(char) * 2);
		g_info.str[0] = g_info.temp_c;
		g_info.str[1] = '\0';
	}
	else
	{
		tmp = g_info.str;
		g_info.str = ft_strjoin(g_info.str, &g_info.temp_c);
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

void	handle_sigusr(int sig)
{
	if (!g_info.index)
	{
		string_saver();
		g_info.temp_c = 0;
		g_info.index = 0b10000000;
	}
	if (sig == SIGUSR1)
	{
		g_info.temp_c += g_info.index;
		g_info.index >>= 1;
	}
	else if (sig == SIGUSR2)
	{
		g_info.index >>= 1;
	}
	if (!g_info.index && !g_info.temp_c)
	{
		ft_printf("STR[%s]\n", g_info.str);
		free(g_info.str);
		g_info.str = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID =  %i\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}