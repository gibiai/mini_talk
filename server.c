/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:43:15 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/28 20:25:52 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███   ███  ██ ███    ██ ██      ████████  █████ ██  \
	██   ██ %s\n", YELLOW, END);
	ft_printf("\t%s████  ████ ██ ████   ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", YELLOW, END);
	ft_printf("\t%s██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██     \
	█████   %s\n", YELLOW, END);
	ft_printf("\t%s██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", YELLOW, END);
	ft_printf("\t%s██      ██ ██ ██   ████ ██        ██    ██   ██ ███████\
	██   ██ %s\n", YELLOW, END);
	ft_printf("\n\t%sPID: %d%s", RED, pid, END);
}

int	isQuitKeyPressed()
{
	int	c;

	c = getchar();
	if (c == 'q' || c == 'Q')
	{
		return (1);
	}
	return (0);
}

int	ft_handler(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	if (signo == SIGUSR2)
		c |= 1 << i;
	if (++i == 8)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	(void)context;
	return (0);
}

int	main(void)
{
	struct sigaction	sa;
	int			pid;

	display_banner(pid);
	ft_printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void *)ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (isQuitKeyPressed())
		{
			printf("%sExiting program...%s\n", YELLOW, END);
			break;
		}
		pause();
	}
	return (0);
}
