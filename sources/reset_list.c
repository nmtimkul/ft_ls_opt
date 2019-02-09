/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:10:03 by nmtimkul          #+#    #+#             */
/*   Updated: 2019/02/02 12:09:48 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_freelst(t_lst *lst)
{
	t_lst	*elem;
	t_lst	*tmp;

	elem = lst;
	while (elem)
	{
		tmp = elem->next;
		ft_memdel((void *)&elem->stat);
		ft_strdel(&elem->d_name);
		free(elem);
		elem = tmp;
	}
}
