/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:00:02 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 11:00:05 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/superlibft.h"
#include <math.h>

typedef struct		s_link
{
	struct s_room	*room;
	int				dist;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*id;
	int				x;
	int				y;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef	struct		s_vpath
{
	char			**path;
	int				len;
	struct	s_vpath	*next;
}					t_vpath;

typedef	struct		s_data
{
	int				ants;
	int				rooms;
	char			st_ed;
	char			*start_id;
	char			*end_id;
	char			flag;
	t_room			*room;
	t_vpath			*valid;
	t_vpath			*optimal;
}					t_data;


/*
** --------------- main.c --------------
*/

void	error(char *line);
void	load_data(t_data *data);
t_data	*init_data(void);

/*
** --------------- parse.c --------------
*/

void	parse_comment(t_data *data, char *line);
void	parse_link(t_data *data, char *line);
t_room	*parse_room(t_data *data, char *line);
void	parse_data(t_data *data, char *line);

/*
** --------------- debug.c --------------
*/

void	print_rooms(t_data *data);
void	print_links(t_data *data);
void	print_local_path(char **path, int len);
void	print_valid_paths(t_data *data);
void	print_optimal_paths(t_data *data);

/*
** --------------- path.c --------------
*/

char	**copy_path(char **dest, char **src, int n);
t_vpath	*add_path(t_vpath *valid, char **path, int path_len);
int		search_path(char **path, char *room_id, int path_len);
void	find_path(t_data *data, t_room *room, char **path, int path_len);
void	start_path(t_data *data);

/*
** --------------- valid.c --------------
*/

int		path_cmp(t_vpath *chosen, t_vpath *valid);
t_vpath	*check_tmp(t_data *data, t_vpath *valid, t_vpath *tmp);
void	find_optimal_paths(t_data *data);