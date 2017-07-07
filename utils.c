/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:38:58 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/07 10:39:09 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_new_path(char *original, char *dir)
{
	char	*new_path;

	new_path = ft_strjoin(original, "/");
	new_path = ft_strjoin(new_path, dir);
	return (new_path);
}

void	ft_permissions(t_ent *file)
{
	struct stat	stats;

	if (stat(file->path, &stats) == -1)
		ft_error("ft_getstats: Failed to get stats of file");
	else
	{
		file->permissions[0] = (S_ISDIR(stats.st_mode)) ? 'd' : '-';
		file->permissions[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
		file->permissions[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
		file->permissions[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
		file->permissions[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
		file->permissions[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
		file->permissions[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
		file->permissions[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
		file->permissions[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
		file->permissions[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
		file->permissions[10] = '\0';
	}
}

t_ent	ft_stats(char *path, t_ent file, char *d_name)
{
	struct stat	stats;	
	
	if (stat(path, &stats) == -1)
	{
		ft_error("ft_stats: Failed to get stats of file");
	}
	else
	{
		file.path = path;
		ft_permissions(&file);
		file.name = d_name;
		file.numLinks = (int)stats.st_nlink;
		file.username = getpwuid(stats.st_uid)->pw_name;
		file.groupname = getgrgid(stats.st_gid)->gr_name;
		file.byteSize = (int)stats.st_size;
		file.blockSize = (int)stats.st_blocks;
		file.dateModified = ctime(&stats.st_mtime);
	}
	return (file);
}

int		ft_is_dir(char *path)
{
	DIR	*d;
	
	if ((d = opendir(path)) != NULL)
	{
		closedir(d);
		return (1);
	}
	return (0);

}

void	ft_error(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}
