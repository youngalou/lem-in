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

#include "../lem-in.h"

int		path_cmp(t_vpath *optimal, t_vpath *valid)
{
	int		i;
	int		j;
	
	while (optimal)
	{
		i = 1;
		while (i < valid->len)
		{
			j = 1;
			while (j < optimal->len)
			{
				if (!ft_strcmp(valid->path[i], optimal->path[j]))
					return (1);
				j++;
			}
			i++;
		}
		optimal = optimal->next;
	}
	return (0);
}

t_vpath	*check_tmp(t_data *data, t_vpath *valid, t_vpath *tmp)
{
	if (!tmp || valid->len < tmp->len)
	{
		if (path_cmp(data->optimal, valid))
			return (tmp);
		data->flag = 0;
		return (valid);
	}
	return (tmp);
}

void	find_optimal_paths(t_data *data)
{
	t_vpath	*valid;
	t_vpath *tmp;

	data->flag = 0;
	while (!data->flag)
	{
		data->flag = 1;
		valid = data->valid;
		tmp = NULL;
		while (valid)
		{
			tmp = check_tmp(data, valid, tmp);
			valid = valid->next;
		}
		if (!data->flag)
			data->optimal = add_path(data->optimal, tmp->path, tmp->len);
	}
}