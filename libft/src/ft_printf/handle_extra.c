/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:36:36 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:44:01 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*add_padding(char *s, int len, t_args *mod)
{
	char	*padding;
	char	*tmp;
	char	*pre;

	if (len < 1)
		return (s);
	(mod->prec >= 0 && mod->length >= 0) ? mod->pad = ' ' : 0;
	pre = move_prefix(mod);
	mod->tmp = s;
	(mod->pre && mod->pad == '0') ? s++ : 0;
	(mod->hash > 1 && mod->pad == '0') ? s++ : 0;
	padding = ft_strnew(len);
	while (--len >= 0)
		padding[len] = mod->pad;
	tmp = (mod->align == 0) ? ft_strjoin(padding, s) : ft_strjoin(s, padding);
	s = tmp;
	if (pre && mod->pad == '0')
	{
		s = ft_strjoin(pre, tmp);
		ft_strdel(&tmp);
	}
	ft_strdel(&mod->tmp);
	ft_strdel(&padding);
	ft_strdel(&pre);
	return (s);
}

char		*move_prefix(t_args *mod)
{
	char	*pre;

	if (mod->hash == 0 && mod->pre == -1)
		return (NULL);
	pre = (char*)malloc(3);
	pre[0] = mod->pre;
	pre[1] = '\0';
	if (mod->hash == 2)
		pre[1] = 'x';
	else if (mod->hash == 3)
		pre[1] = 'X';
	pre[2] = '\0';
	return (pre);
}

char		*add_prefix(char *s, t_args *mod)
{
	char	pre[2];
	char	*tmp;
	int		i;

	i = 0;
	while (s[i])
	{
		if (!mod->pre || s[i] == '-')
			return (s);
		i++;
	}
	pre[0] = mod->pre;
	pre[1] = '\0';
	tmp = ft_strjoin(pre, s);
	ft_strdel(&s);
	return (tmp);
}

char		*add_hash(char *s, t_args *mod)
{
	char	pre[3];
	char	*tmp;

	if (!mod->hash || ((!*s || (ft_strcmp(s, "0") == 0)) && mod->addr == 0))
		return (s);
	mod->pre = '0';
	pre[0] = mod->pre;
	pre[1] = '\0';
	if (mod->hash == 2)
		pre[1] = 'x';
	else if (mod->hash == 3)
		pre[1] = 'X';
	pre[2] = '\0';
	tmp = ft_strjoin(pre, s);
	ft_strdel(&s);
	return (tmp);
}
