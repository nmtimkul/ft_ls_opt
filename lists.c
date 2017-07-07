/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:02:00 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/07 10:51:10 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_node_insert(t_ent file, n_node *list)
{
	n_node	*temp;
	n_node	*temp2;

	temp = (n_node*)malloc(sizeof(n_node));
	temp2 = list;
	if (temp)
	{
		temp->file = malloc(sizeof(file));
		ft_memcpy(temp->file, &file, sizeof(file));
		temp->next = NULL;
	}
	if (temp2->next)
	{
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp;
	}
	else
		list->next = temp;
}

void	ft_time(n_node *list)
{
	n_node	*src;
	n_node	*src2;
	n_node	*temp;
	t_ent	*file;
	t_ent	*file2;

	src = list;
	while (src->next)
	{
		src = src->next;
		file = (t_ent*)src->file;
		src2 = list;
		while (src2->next)
		{
			src2 = src->next;
			file2 = (t_ent*)src->file;
			if (ft_strcmp(file2->dateModified, file->dateModified) > 1)
			{
				temp->file = src->file;
				src->file = src2->file;
				src2->file = temp->file;
			}
		}
	}
}
