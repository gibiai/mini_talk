/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:11:20 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/02 17:11:20 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nbr)
{
	int	index;

	index = 0;
	index += ft_putstr("0x");
	if (nbr == 0)
		index += ft_putchar('0');
	else
		index += ft_puthexa(nbr, "0123456789abcdef");
	return (index);
}
