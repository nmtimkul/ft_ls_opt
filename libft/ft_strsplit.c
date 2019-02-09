/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:59:02 by nmtimkul          #+#    #+#             */
/*   Updated: 2018/06/15 11:20:56 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nwords(char *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || !s[i - 1]))
			n++;
		i++;
	}
	return (n);
}

static char	*add(char *s, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**ret;

	if (!s || !s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * nwords((char *)s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || !s[i - 1]))
			ret[j++] = add((char *)s + i, c);
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
