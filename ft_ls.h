/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:59:07 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/07 10:51:35 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>

typedef struct		s_node
{
	void			*file;
	struct s_node	*next;
}					n_node;

typedef struct	s_ent
{
	char		*path;
	char		permissions[11];
	int			numLinks;
	char		*username;
	char		*groupname;
	int			byteSize;
	int			blockSize;
	int			dirSize;
	char		*dateModified;
	n_node		*subDirs;
	char		*name;
}				t_ent;

typedef struct	s_mint
{
	int			i;
	int			j;
	int			k;
}				t_mint;

int		main(int argc, char **argv);
int		ft_ls(char *path, char *options);
void	ft_std_list(char *path, char *options, n_node **list);
void	ft_rec_list(char *path, char *options, n_node **list);
char	*ft_new_path(char *original, char *dir);
void	ft_permissions(t_ent *file);
t_ent	ft_stats(char *path, t_ent file, char *d_name);
int		ft_is_dir(char *path);
void	ft_error(char *error);
void	ft_node_insert(t_ent file, n_node *list);
int		ft_long_printer(char *options, n_node *list);
int		ft_printer(char *options, n_node *list);
void	ft_time(n_node *list);

#endif
