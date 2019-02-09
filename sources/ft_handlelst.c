/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlelst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:11:51 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:07:50 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_handlelst(t_lst **elem, char *d_name, char *flag)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = *elem;
	if (elem != NULL)
	{
		new = create_lst(d_name, flag);
		new->next = tmp->next;
		tmp->next = new;
	}
	else
		tmp->next = create_lst(d_name, flag);
}

void	ft_lstp(t_lst ***begin, char *d_name, char *flag)
{
	t_lst	*new;

	new = create_lst(d_name, flag);
	if (**begin)
		new->next = **begin;
	**begin = new;
}

void	ft_lstb(t_lst **begin, char *d_name, char *flag)
{
	t_lst	*elem;

	elem = *begin;
	if (elem != NULL)
	{
		while (elem->next)
			elem = elem->next;
	}
	elem->next = create_lst(d_name, flag);
}
