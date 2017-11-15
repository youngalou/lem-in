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

typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				id;
	int				x;
	int				y;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef	struct		s_data
{
	int				ants;
	int				rooms;
	char			st_ed;
	int				start;
	int				end;
	t_room			*room;
}					t_data;


/*
** --------------- main.c --------------
*/

void	load_data(t_data *data);
t_data	*init_data(void);

/*
** --------------- parse.c --------------
*/

void	error(void);
void	parse_comment(t_data *data, char *line);
void	parse_link(t_data *data, char *line);
t_room	*parse_room(t_data *data, char *line);
void	parse_data(t_data *data, char *line);

/*
** --------------- debug.c --------------
*/

void	print_rooms(t_data *data);
void	print_hash(t_data *data);
void	print_links(t_data *data);