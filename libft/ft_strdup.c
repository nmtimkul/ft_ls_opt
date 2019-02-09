/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:10:17 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/05 13:55:05 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;

	str1 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str1 != NULL)
		return (ft_strcpy(str1, s1));
	else
		return (NULL);
}
