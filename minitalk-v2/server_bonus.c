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

static t_info	*g_start;

int	reseter(t_info *client, int success)
{
	if (!success)
		kill(client->client_pid, SIGUSR2);
	// client->client_pid = 0;
	if (client->str)
	{
		free(client->str);
		client->str = NULL;
	}
	client->temp_c = 0;
	client->index = 0;
	// remove_node();
	return (0);
}

int	string_saver(t_info *client)
{
	char	*tmp;

	if (!client->temp_c)
	{
		// ft_printf("once\n");
		return (1);
	}
	if (!client->str)
	{
		client->str = malloc(sizeof(char) * 2);
		if (!client->str)
			return (reseter(client, 0));
		client->str[0] = client->temp_c;
		client->str[1] = '\0';
	}
	else
	{
		tmp = client->str;
		client->str = ft_strjoin(client->str, &client->temp_c);
		free(tmp);
		tmp = NULL;
		if (!client->str)
			return (reseter(client, 0));
	}
	return (1);
}

void	handle_sigusr(int sig, siginfo_t *sa_info, void *context)
{
	t_info	*client;

	(void)context;
	client = g_start;
	if (!client || client->client_pid != sa_info->si_pid)
	{
		client = find_client(client, sa_info->si_pid);
		if (!g_start)
			g_start = client;
	}
	// ft_printf("client->index[%i], client->temp_c[%i]\n", client->index, client->temp_c);
	if (!client->index)
	{
		if (!string_saver(client))
			return ;
		client->temp_c = 0;
		client->index = 0b10000000;
		// ft_printf("client->index[%i]\n", client->index);
	}
	// ft_printf("CLIENT PID [%i]\n", client->client_pid);
	if (sig == SIGUSR1)
		client->temp_c += client->index;
	client->index >>= 1;
	// ft_printf("client->temp_c[%i]\n",client->temp_c);
	if (!client->index && !client->temp_c)
	{
		// ft_printf("CLIENT PID END[%i]\n", client->client_pid);
		kill(client->client_pid, SIGUSR1);
		ft_printf("%s\n", client->str);
		reseter(client, 1);
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
