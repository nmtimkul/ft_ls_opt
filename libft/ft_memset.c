/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:37:24 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/12 08:31:51 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*temp;

	count = 0;
	temp = (unsigned char *)b;
	while (count < len)
	{
		temp[count] = c;
		count++;
	}
	return ((void *)temp);
}
