/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:40:54 by gde-carl          #+#    #+#             */
/*   Updated: 2023/04/06 21:28:13 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*newstr;
	size_t			i;

	i = 0;
	newstr = (unsigned char *)str;
	while (i < n)
		newstr[i++] = c;
	return (str);
}
