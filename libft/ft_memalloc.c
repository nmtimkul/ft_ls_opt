/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:54:24 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:05:55 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (void *)malloc(sizeof(mem) * size);
	if (mem == NULL)
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}
