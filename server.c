/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:21:21 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/27 17:21:27 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s_      _  _      _        _____  ____  _     _  __%s\n", YELLOW, END);
	ft_printf("\t%s/ \__/|/ \/ \  /|/ \      /__ __\/  _ \/ \   / |/ /%s\n", YELLOW, END);
	ft_printf("\t%s| |\/||| || |\ ||| |        / \  | / \|| |   |   / %s\n", YELLOW, END);
	ft_printf("\t%s| |  ||| || | \||| |        | |  | |-||| |_/\|   \ %s\n", YELLOW, END);
	ft_printf("\t%s\_/  \|\_/\_/  \|\_/        \_/  \_/ \|\____/\_|\_\%s\n", YELLOW, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%s", RED, pid, END);
}

void	signal_error(void)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RED, END);
	exit(EXIT_FAILURE);
}

void	ft_server_receiver(int sig, siginfo_t *info, void *context)
{
	static	int	i;
	static	char	c;

	i = 0;
	c = 0;
	(void)context;
	if (Sig == SIGUSR2)
		c |= 0 << i;
	else if (sig == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			signal_error();
		exit(EXIT_FAILURE);
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
			signal_error();
}

int main(void)
{
	struct sigaction	sa_sig;
	ft_printf("PID: %d\n", GREEN, getpid());
	while(1)
	{
		sa_sig.sa_flags = SA_SIGINFO;
		sa_sig.sa_sigaction = ft_server_receiver;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			ft_printf("ERROR: %s\n", strerror(errno));
		if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
			ft_printf("ERROR: %s\n", strerror(errno));
		pause();
	}
	return (0);
}
