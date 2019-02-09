/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:23:02 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/06 13:31:41 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstt;
	char	*srcc;

	i = 0;
	dstt = (char*)dst;
	srcc = (char*)src;
	if (dstt > srcc)
	{
		while ((int)--len >= 0)
			dstt[len] = srcc[len];
	}
	else if (dstt < srcc)
	{
		while (i < len)
		{
			dstt[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
