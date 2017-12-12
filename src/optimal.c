/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:46:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/12/04 12:46:28 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		path_cmp(t_vpath *opt, t_vpath *vld)
{
	int		i;
	int		j;

	while (opt)
	{
		i = 1;
		while (i < vld->len)
		{
			j = 1;
			while (j < opt->len)
			{
				if (!ft_strcmp(vld->path[i], opt->path[j]))
					return (1);
				j++;
			}
			i++;
		}
		opt = opt->next;
	}
	return (0);
}

t_vpath	*check_tmp(t_data *data, t_vpath *vld, t_vpath *tmp)
{
	if (!tmp || vld->len < tmp->len)
	{
		if (path_cmp(data->optimal, vld))
			return (tmp);
		data->flag = 0;
		return (vld);
	}
	return (tmp);
}

void	find_optimal_paths(t_data *data)
{
	t_vpath	*vld;
	t_vpath *tmp;

	data->flag = 0;
	while (!data->flag)
	{
		data->flag = 1;
		vld = data->valid;
		tmp = NULL;
		while (vld)
		{
			tmp = check_tmp(data, vld, tmp);
			vld = vld->next;
		}
		if (!data->flag)
			data->optimal = add_path(data->optimal, tmp->path, tmp->len);
	}
}
