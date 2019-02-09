/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:57:15 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/15 11:17:32 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*j;
	char		*srcc;
	size_t		len;

	j = (char *)ft_memchr(dst, '\0', dstsize);
	if (j == NULL)
		return (dstsize + ft_strlen(src));
	srcc = (char *)src;
	len = (size_t)(j - dst) + ft_strlen(srcc);
	while ((size_t)(j - dst) < dstsize - 1 && *srcc != '\0')
	{
		*j = *srcc;
		j++;
		srcc++;
	}
	*j = '\0';
	return (len);
}
