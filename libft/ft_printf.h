/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:09:42 by gde-carl          #+#    #+#             */
/*   Updated: 2023/05/27 18:03:48 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int	ft_allcases(va_list args, const char c);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long nbr, char *hexa);
int	ft_putnbr(int nbr);
int	ft_putptr(unsigned long nbr);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int nbr);

#endif
