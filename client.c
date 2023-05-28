/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:21:07 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/27 17:48:05 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(void)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RED, END);
	exit(EXIT_FAILURE);
}

void	end_coms(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Message received\n", GREEN);
		exit(EXIT_SUCCESS);
	}
}

void	ft_send_char_bit_by_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
			c >>= 1;
			bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	signal(SIGUSR2, end_coms);
	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
			ft_send_char_bit_by_bit(pid, argv[2][i++]);
		ft_send_char_bit_by_bit(pid, '\0');
	}
	else
	{
		ft_printf("%susage: ./client <server_pid> <text to send>%s\n",
			RED);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
