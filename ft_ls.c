/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:44:26 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/07 10:38:13 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_printer(char *options, n_node *list)
{
	n_node	*src;
	t_ent	*file;
	int		ret;

	src = list;
	while (src->next)
	{
		src = src->next;
		file = (t_ent*)src->file;
		ft_putendl(file->name);
	}
	if (strchr(options, 'R') != NULL)
	{
		src = list;
		while (src)
		{
			src = src->next;
			file = (t_ent*)src->file;
			if (ft_is_dir(file->path) == 1 && (ft_strcmp(file->path, ".") != 0
						|| ft_strcmp(file->path, "..") != 0))
				ret = ft_printer(options, file->subDirs);
		}
	}
	else
		ret = 1;
	return (ret);
}

int		ft_long_printer(char *options, n_node *list)
{
	n_node	*src;
	t_ent	*file;
	int		ret;

	src = list;
	while(src->next)
	{
		src = src->next;
		file = (t_ent*)src->file;
		printf("%s %2d %s  %s %5d %s %s\n", file->permissions, file->numLinks, 
				file->username, file->groupname, file->byteSize, 
				ft_strsub(file->dateModified, 4, 12), file->name);
	}
	if (strchr(options, 'R') != NULL)
	{
		src = list;
		while(src)
		{
			src = src->next;
			file = (t_ent*)src->file;
			if(ft_is_dir(file->path) == 1)
				if(ft_is_dir(file->path) == 1 && (ft_strcmp(file->path, ".") != 0 
							|| ft_strcmp(file->path, "..") != 0))
					ret = ft_long_printer(options, file->subDirs);
		}
	}
	else
		ret = 1;
	return (ret);
}

int		ft_ls(char *path, char *options)
{
	int		ret;
	n_node	*list;

	ret = 0;
	list = (n_node*)malloc(sizeof(n_node));
	list->next = NULL;
	if (ft_strlen(path) == 0)
		ft_strcpy(path, ".");
	if (strchr(options, 'R') != NULL)
		ft_rec_list(path, options, &list);
	else
		ft_std_list(path, options, &list);
	if (strchr(options, 't') != NULL)
		ft_time(list);
	if (strchr(options, 'r') != NULL)
		printf("\n\nthere is a r 0_o\n\n");
	if(strchr(options, 'l') != NULL)
		ft_long_printer(options, list);
	else
		ft_printer(options, list);
	free(list);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_mint	ints;
	char	*path;
	char	*options;

	ints.i = 0;
	ints.k = 0;
	options = malloc(sizeof(char) * 6);
	path = malloc((sizeof(char) * 255) + 1);
	while (++ints.i < argc)
	{
		if (argv[ints.i][0] == '-')
		{
			ints.j = 1;
			while (ints.j < ft_strlen(argv[ints.i]))
			{
				options[ints.k] = argv[ints.i][ints.j];
				ints.j++;
				ints.k++;
			}
		}
		else
			ft_strcpy(path, argv[ints.i]);
	}
	options[ints.k] = '\0';
	return (ft_ls(path, options));
}
