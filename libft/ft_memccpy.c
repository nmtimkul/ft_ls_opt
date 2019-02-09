/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:07:14 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:06:11 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*dstt;

	i = 0;
	srcc = (unsigned char *)src;
	dstt = (unsigned char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		if (dstt[i] == (unsigned char)c)
			return ((void *)dstt + i + 1);
		i++;
	}
	return (NULL);
}
