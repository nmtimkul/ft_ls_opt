/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:02:57 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/15 11:06:46 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
		if (!ft_memcmp(haystack++, needle, i))
			return ((char *)haystack - 1);
	return (0);
}
