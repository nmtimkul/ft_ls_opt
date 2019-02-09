/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:37:34 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/06 14:04:29 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	tmp = (char *)malloc(sizeof(char) * i);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tmp[i++] = *s2;
		s2++;
	}
	tmp[i] = '\0';
	return (tmp);
}
