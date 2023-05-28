/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:11:21 by gde-carl          #+#    #+#             */
/*   Updated: 2023/04/06 21:00:29 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *find, size_t n)
{	
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(find))
		return ((char *)dest);
	if (!n)
		return (NULL);
	while (dest[i] != '\0' && i < n)
	{	
		j = 0;
		while (dest[i + j] == find[j] && (i + j) < n)
		{	
			j ++;
			if (find[j] == '\0')
				return ((char *)(dest + i));
		}
		i ++;
	}
	return (0);
}
