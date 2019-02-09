/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:12:57 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:08:55 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*clean_names(char *s, int err)
{
	int			len;

	if (err == 20)
		return (s);
	if (!ft_strchr(s, '/'))
		return (s);
	len = ft_strlen(s);
	len--;
	if (s[len] == '/')
		len--;
	while (s[len] != '/')
		len--;
	len++;
	return (&s[len]);
}

void	ft_sortascii(t_lst **lst, char *d_name, char *flag)
{
	t_lst		*elem;

	elem = *lst;
	if (elem && ft_strcmp(clean_names(elem->d_name, 0),
	clean_names(d_name, 0)) >= 0)
	{
		ft_lstp(&lst, d_name, flag);
		return ;
	}
	while (elem->next && ft_strcmp(clean_names(elem->next->d_name, 0),
	clean_names(d_name, 0)) < 0)
		elem = elem->next;
	if (elem)
		ft_handlelst(&elem, d_name, flag);
}

void	ft_sorttime2(t_lst *elem, char *d_name, char *flag, struct stat s)
{
	t_lst		*prev;

	prev = elem;
	while (elem->next && T_SECN >= TV_SEC)
	{
		if (T_SECN > TV_SEC)
		{
			prev = elem;
			elem = elem->next;
		}
		else if (T_SECN == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSECN > TV_NSEC)
				elem = elem->next;
			else if (elem->next && T_NSECN == TV_NSEC &&
				ft_strcmp(elem->next->d_name, d_name) < 0)
				elem = elem->next;
			else
				break ;
		}
	}
	if (elem)
		ft_handlelst(&elem, d_name, flag);
}

void	ft_sorttime(t_lst **lst, char *d_name, char *flag)
{
	t_lst		*elem;
	struct stat	s;

	elem = *lst;
	lstat(d_name, &s);
	TV_SEC = s.st_mtimespec.tv_sec;
	if (elem && T_SEC <= TV_SEC)
	{
		if (T_SEC < TV_SEC)
		{
			ft_lstp(&lst, d_name, flag);
			return ;
		}
		else if (T_SEC == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSEC < TV_NSEC || (elem->next && T_NSEC == TV_NSEC &&
				ft_strcmp(elem->next->d_name, d_name) >= 0))
			{
				ft_lstp(&lst, d_name, flag);
				return ;
			}
		}
	}
	ft_sorttime2(elem, d_name, flag, s);
}

void	ft_sortlst(t_lst **lst, char *d_name, char *flag)
{
	t_lst		*elem;

	elem = *lst;
	if (T == '1' && RM == '0')
		ft_sorttime(lst, d_name, flag);
	else if (RM == '1')
		ft_sortrev(lst, d_name, flag);
	else
	{
		if (elem && ft_strcmp(clean_names(elem->d_name, 0),
		clean_names(d_name, 0)) >= 0)
		{
			ft_lstp(&lst, d_name, flag);
			return ;
		}
		while (elem->next && ft_strcmp(clean_names(elem->next->d_name, 0),
		clean_names(d_name, 0)) < 0)
			elem = elem->next;
		if (elem)
			ft_handlelst(&elem, d_name, flag);
	}
}
