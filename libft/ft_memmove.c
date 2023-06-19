/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:10:29 by gibiai            #+#    #+#             */
/*   Updated: 2023/06/19 19:43:32 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dest && !src) || (src == dest))
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{	
		i = n - 1;
		while (i > 0 && i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i --;
		}
	}
	else
	{
		while (i < n)
		{	
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i ++;
		}
	}
	return (dest);
}
