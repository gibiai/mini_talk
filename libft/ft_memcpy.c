/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:02 by gde-carl          #+#    #+#             */
/*   Updated: 2023/04/07 23:05:37 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest1 = dest;
	src1 = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dest1++ = *src1++;
	return (dest);
}
