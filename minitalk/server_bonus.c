/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:27:52 by leklund           #+#    #+#             */
/*   Updated: 2023/01/18 17:27:54 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/server_bonus.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static t_info	g_info;

int	reseter(int success)
{
	if (!success)
		kill(g_info.client_pid, SIGUSR2);
	g_info.client_pid = 0;
	if (g_info.str)
	{
		free(g_info.str);
		g_info.str = NULL;
	}
	g_info.temp_c = 0;
	g_info.index = 0;
	return (0);
}

int	string_saver(void)
{
	char	*tmp;

	if (!g_info.temp_c)
		return (1);
	if (!g_info.str)
	{
		g_info.str = malloc(sizeof(char) * 2);
		if (!g_info.str)
			return (reseter(0));
		g_info.str[0] = g_info.temp_c;
		g_info.str[1] = '\0';
	}
	else
	{
		tmp = g_info.str;
		g_info.str = ft_strjoin(g_info.str, &g_info.temp_c);
		free(tmp);
		tmp = NULL;
		if (!g_info.str)
			return (reseter(0));
	}
	return (1);
}

void	handle_sigusr(int sig, siginfo_t *sa_info, void *context)
{
	(void)context;
	if (!g_info.client_pid)
		g_info.client_pid = sa_info->si_pid;
	if (!g_info.index)
	{
		if (!string_saver())
			return ;
		g_info.temp_c = 0;
		g_info.index = 0b10000000;
	}
	if (sig == SIGUSR1)
		g_info.temp_c += g_info.index;
	g_info.index >>= 1;
	if (!g_info.index && !g_info.temp_c)
	{
		kill(g_info.client_pid, SIGUSR1);
		ft_printf("%s\n", g_info.str);
		reseter(1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID =  %i\n", pid);
	while (1)
		pause();
	return (0);
}
