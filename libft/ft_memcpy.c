/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:06:12 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/07 15:35:48 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*srcc;
	char	*dstt;

	i = 0;
	srcc = (char *)src;
	dstt = (char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return ((void *)dstt);
}
