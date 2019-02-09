/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:13:54 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:09:09 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_time_rev2(t_lst *elem, char *d_name, char *flag, struct stat s)
{
	while (elem->next && T_SECN <= TV_SEC)
	{
		if (T_SECN < TV_SEC)
			elem = elem->next;
		else if (T_SECN == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSECN < TV_NSEC)
				elem = elem->next;
			else if (elem->next && T_NSECN == TV_NSEC &&
				ft_strcmp(elem->next->d_name, d_name) > 0)
				elem = elem->next;
			else
				break ;
		}
	}
	if (elem)
		ft_handlelst(&elem, d_name, flag);
}

void	ft_sort_time_rev(t_lst **lst, char *d_name, char *flag)
{
	t_lst		*elem;
	struct stat	s;

	elem = *lst;
	lstat(d_name, &s);
	TV_SEC = s.st_mtimespec.tv_sec;
	if (elem && T_SEC >= TV_SEC)
	{
		if (T_SEC > TV_SEC)
		{
			ft_lstp(&lst, d_name, flag);
			return ;
		}
		else if (T_SEC == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSEC > TV_NSEC || (T_NSEC == TV_NSEC &&
			(ft_strcmp(elem->d_name, d_name) <= 0)))
			{
				ft_lstp(&lst, d_name, flag);
				return ;
			}
		}
	}
	ft_sort_time_rev2(elem, d_name, flag, s);
}

void	ft_sortrev(t_lst **lst, char *d_name, char *flag)
{
	t_lst		*elem;

	elem = *lst;
	if (RM == '1' && T == '0')
	{
		if (elem && ft_strcmp(clean_names(elem->d_name, 0),
		clean_names(d_name, 0)) <= 0)
		{
			ft_lstp(&lst, d_name, flag);
			return ;
		}
		while (elem->next && ft_strcmp(clean_names(elem->next->d_name, 0),
		clean_names(d_name, 0)) > 0)
			elem = elem->next;
		if (elem)
			ft_handlelst(&elem, d_name, flag);
	}
	if (RM == '1' && T == '1')
		ft_sort_time_rev(lst, d_name, flag);
}
