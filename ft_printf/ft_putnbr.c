/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:11:03 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/02 17:11:03 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	index;

	index = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		index += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		index += ft_putnbr(nbr / 10);
	index += ft_putchar(nbr % 10 + '0');
	return (index);
}
