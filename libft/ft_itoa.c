/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:25:35 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:05:37 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	k;

	k = (long)n;
	i = len(k);
	if (!(ret = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i--] = '\0';
	if (k < 0)
	{
		ret[0] = '-';
		k = -k;
	}
	ret[i--] = (k % 10) + '0';
	k /= 10;
	while (k)
	{
		ret[i--] = (k % 10) + '0';
		k /= 10;
	}
	return (ret);
}
