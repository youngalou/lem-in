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

char	**copy_path(char **dest, char **src, int n)
{
	int		i;

	dest = (char**)malloc(sizeof(char*) * n);
	i = 0;
	while (i < n)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

void	add_valid_path(t_data *data, char **path, int path_len)
{
	t_vpath *valid;
	t_vpath *new;

	new = malloc(sizeof(t_vpath));
	new->path = copy_path(new->path, path, path_len + 1);
	new->len = path_len;
	new->next = NULL;
	if (!data->valid)
	{
		data->valid = new;
		return ;
	}
	valid = data->valid;
	while (valid->next)
		valid = valid->next;
	valid->next = new;
}
