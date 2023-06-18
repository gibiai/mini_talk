/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:10:47 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:47 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, char *hexa)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthexa(nbr / 16, hexa);
	i += ft_putchar(hexa[nbr % 16]);
	return (i);
}
