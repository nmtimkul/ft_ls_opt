/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:26:02 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/15 08:36:04 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s1 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
