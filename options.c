/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:08:04 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/07 10:51:29 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_std_list(char *path, char *options, n_node **list)
{
	DIR				*d;
	struct dirent	*dir;
	t_ent			file;
	
	if ((d = opendir(path)) == NULL)
		ft_error("No such file or directory");
	while ((dir = readdir(d)) != NULL)
	{
		if (ft_strchr(options, 'a') == NULL && dir->d_name[0] == '.')
			continue;
		file = ft_stats(ft_new_path(path, dir->d_name), file, dir->d_name);
		ft_node_insert(file, *list);
		file.dirSize++;
	}
	free(dir);
	closedir(d);
}

void	ft_rec_list(char *path, char *options, n_node **list)
{
	DIR		*d;
	struct dirent	*dir;
	t_ent		file;
	n_node		*new_list;

	new_list = (n_node*)malloc(sizeof(n_node));
	if ((d = opendir(path)) == NULL)
		ft_error("No such file or directory");
	while ((dir = readdir(d)) != NULL)
	{
		if (ft_strchr(options, 'a') == NULL && dir->d_name[0] == '.')
			continue;
		file = ft_stats(ft_new_path(path, dir->d_name), file, dir->d_name);
		if(ft_is_dir(ft_new_path(path, dir->d_name)) == 1 && 
				(ft_strcmp(dir->d_name, ".") != 0 || 
				 ft_strcmp(dir->d_name, "..") != 0))
		{
			new_list = file.subDirs;
			new_list->next = NULL;
			ft_rec_list(ft_new_path(path, dir->d_name), options, &file.subDirs);
		}
		ft_node_insert(file, *list);
		file.dirSize++;
	}
	closedir(d);
	free(dir);
	free(new_list);
}
