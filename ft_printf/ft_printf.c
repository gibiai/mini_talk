/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:09:06 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/27 17:53:06 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_allcases(va_list args, const char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		length += ft_putptr(va_arg(args, unsigned long));
	else if (c == 'u')
		length += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		length;

	index = 0;
	length = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			length += ft_allcases(args, format[index]);
		}
		else
			length += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (length);
}
