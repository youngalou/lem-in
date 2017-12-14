/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:00:02 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 11:00:05 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/superlibft.h"
# include <math.h>

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
	char			vac;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef	struct		s_vpath
{
	char			**path;
	int				len;
	int				cost;
	struct s_vpath	*next;
}					t_vpath;

typedef	struct		s_ant
{
	int				num;
	t_vpath			*route;
	int				pos;
}					t_ant;

typedef	struct		s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

typedef	struct		s_data
{
	int				ants;
	int				rooms;
	char			st_ed;
	char			*start_id;
	char			*end_id;
	char			flag;
	t_line			*line;
	t_room			*room;
	t_vpath			*valid;
	t_vpath			*optimal;
	t_ant			**ant;
}					t_data;

/*
** --------------- main.c --------------
*/

void				parse_data(t_data *data, char *line);
void				store_line(t_data *data, char *line);
void				load_data(t_data *data);
t_data				*init_data(void);

/*
** --------------- debug.c --------------
*/

void				print_rooms(t_data *data);
void				print_links(t_data *data);
void				print_local_path(char **path, int len);
void				print_optimal_paths(t_data *data);
void				print_ants(t_data *data);

/*
** --------------- parse.c --------------
*/

void				parse_comment(t_data *data, char *line);
t_link				*add_link(t_room *r1, t_room *r2, char *link_id);
void				parse_link(t_data *data, char *line);
t_room				*add_room(t_data *data, char **str);
t_room				*parse_room(t_data *data, char *line);

/*
** --------------- path.c --------------
*/

char				**copy_path(char **dest, char **src, int n);
t_vpath				*add_path(t_vpath *valid, char **path, int path_len);
int					search_path(char **path, char *room_id, int path_len);
void				find_path(t_data *data, t_room *room,
								char **path, int path_len);
void				start_path(t_data *data);

/*
** --------------- optimal.c --------------
*/

int					path_cmp(t_vpath *chosen, t_vpath *valid);
t_vpath				*check_tmp(t_data *data, t_vpath *valid, t_vpath *tmp);
void				find_optimal_paths(t_data *data);

/*
** --------------- ants.c --------------
*/

t_ant				*new_ant(t_vpath *path, int i);
void				assign_ants(t_data *data);
void				move_ants(t_data *data);

/*
** --------------- error.c --------------
*/

void				error_ants(t_data *data, char *line);
int					check_room(t_data *data, char *line);
int					check_link(t_data *data, char *line);
int					check_comment(t_data *data, char *line);

/*
** --------------- utils.c --------------
*/

void				error(t_data *data);
void				print_input(t_data *data);
int					is_digits(char *line);

/*
** --------------- free.c --------------
*/

void				free_optimal(t_data *data);
void				free_valid(t_data *data);
void				free_rooms(t_data *data);
void				free_all(t_data *data);

#endif
