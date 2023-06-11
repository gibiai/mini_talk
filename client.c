/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:05:33 by gde-carl          #+#    #+#             */
/*   Updated: 2023/06/11 01:09:03 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sent(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("\033[32mMessage sent!\n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_byte(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i++))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
	}
}

void	ft_bit(int pid, char *msg)
{
	while (*msg)
		ft_byte(pid, *msg++);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("%s./client [server-pid] [message]%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	str = argv[2];
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("%sInvalid PID%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &ft_sent);
	ft_bit(pid, str++);
	ft_byte(pid, '\n');
	ft_byte(pid, '\0');
	return (0);
}
