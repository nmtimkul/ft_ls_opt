/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 07:33:10 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/10 10:13:02 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	needlen;
	int		i;

	i = 0;
	needlen = ft_strlen(n);
	if (n[0] == '\0')
		return ((char *)h);
	while (h[i] != '\0' && len >= needlen)
	{
		len--;
		if (h[i] == n[i] && ft_strncmp(h, n, needlen) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
