/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:08:43 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/15 08:07:28 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*tmp;

	tmp = (char *)s2;
	len = 0;
	while (s1[len] != '\0')
		len++;
	i = 0;
	while (tmp[i] != '\0')
	{
		s1[len + i] = tmp[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}
