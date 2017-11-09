/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:43:29 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_args(t_res *res, va_list ap, t_args *mod)
{
	char	*spec;

	spec = res->place + 1;
	init_mods(mod);
	if (res->place - res->fmt)
	{
		check_res(res, res->place - res->fmt);
		ft_strncat(res->out, res->fmt, res->place - res->fmt);
		res->len += res->place - res->fmt;
	}
	if (F_MOD)
		spec = search_mods(res, ap, mod, spec);
	if (F_CONV)
		spec = conversions(res, ap, mod, spec);
	else if (*spec)
	{
		mod->length = -1;
		mod->tmp = add_padding(ft_strndup(spec, 1), mod->width - 1, mod);
		res->len += (mod->width) ? mod->width : 1;
		ft_strcat(res->out, mod->tmp);
		ft_strdel(&mod->tmp);
		spec++;
	}
	return (spec);
}

char	*conversions(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = handle_conv(res, ap, mod, spec);
	if (!s)
		return (spec + 1);
	res->size = ((*s == '\0' && (*spec == 'c' ||
				*spec == 'C')) ? 1 : ft_strlen(s));
	s = add_padding(s, mod->width - res->size, mod);
	res->len += ft_strlen(s);
	check_res(res, ft_strlen(s));
	ft_strcat(res->out, s);
	init_mods(mod);
	ft_strdel(&s);
	return (spec + 1);
}

char	*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (*spec == '%')
	{
		mod->length = -1;
		s = ft_strdup("%");
	}
	if (F_CAPS && mod->length < 3)
		mod->length = 3;
	if (F_UOX || F_DI || F_CAPS)
		s = handle_diuox(res, ap, mod, spec);
	else if (F_SCP)
		s = handle_scp(res, ap, mod, spec);
	return (s);
}

void	replace_null(t_res *res)
{
	int		i;

	i = 0;
	while (res->out[i])
	{
		if (res->out[i] == 127)
			res->out[i] = 0;
		i++;
	}
}
