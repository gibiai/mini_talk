/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:29:49 by gde-carl          #+#    #+#             */
/*   Updated: 2023/04/11 15:42:14 by gde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*duplicate;
	int		i;

	i = 0;
	duplicate = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!duplicate)
		return (0);
	while (s[i])
	{
		duplicate[i] = s[i];
		i ++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
