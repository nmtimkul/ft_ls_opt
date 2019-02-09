/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:06:06 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/10 08:46:43 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*tmp;
	char	*ans;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	while (ft_isspace(tmp[i]))
		i++;
	tmp = ft_strcpy(tmp, tmp + i);
	i = ft_strlen(tmp) - 1;
	while (ft_isspace(tmp[i]))
	{
		tmp[i] = '\0';
		i--;
	}
	ans = ft_strdup(tmp);
	return (ans);
}
