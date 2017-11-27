/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:58:12 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 15:58:13 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void	print_rooms(t_data *data)
{
	t_room	*room;

	ft_printf("start: %s\tend: %s\n", data->start_id, data->end_id);
	room = data->room;
	while (room)
	{
		ft_printf("id: %s\tx: %d\ty: %d\n", room->id, room->x, room->y);
		room = room->next;
	}
}

void	print_links(t_data *data)
{
	t_room	*room;
	t_link	*link;

	room = data->room;
	while (room)
	{
		link = room->link;
		while (link)
		{
			ft_printf("room: %s\tlink: %s\tdist: %d\n", room->id, link->room->id, link->dist);
			link = link->next;
		}
		room = room->next;
	}
}