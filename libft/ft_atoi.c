/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:58 by gde-carl          #+#    #+#             */
/*   Updated: 2023/04/07 23:28:12 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	s = 1;
	i = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * s);
}
