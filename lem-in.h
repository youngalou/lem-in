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
	t_room			*room;
	t_vpath			*valid;
}					t_data;


/*
** --------------- main.c --------------
*/

void	error(void);
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
void	print_paths(t_data *data);
void	print_local_path(t_data *data, char **path);

/*
** --------------- path.c --------------
*/

void	add_to_path(t_data *data, char **path, char *room_id);
int		search_path(t_data *data, char **path, char *room_id);
void	find_path(t_data *data, t_room *room, char **path, int path_len);
void	start_path(t_data *data);

/*
** --------------- valid.c --------------
*/

char	**copy_path(char **dest, char **src, int n);
void	add_valid_path(t_data *data, char **path, int path_len);