/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:12:00 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/02 17:12:00 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	int	index;

	index = 0;
	if (nbr > 9)
		index += ft_putunsigned(nbr / 10);
	index += ft_putchar(nbr % 10 + '0');
	return (index);
}
