/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:44:19 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		init_mods(t_args *mod)
{
	mod->length = 0;
	mod->width = 0;
	mod->prec = -1;
	mod->align = 0;
	mod->pad = ' ';
	mod->pre = 0;
	mod->base = 10;
	mod->hash = 0;
	mod->addr = 0;
	mod->tmp = 0;
}

char		*search_mods(t_res *res, va_list ap, t_args *mod, char *spec)
{
	while (F_MOD)
	{
		while (F_LEN)
			spec = handle_length(mod, spec);
		while (F_FLAGS || *spec == '{')
			spec = handle_flags(res, ap, mod, spec);
	}
	return (spec);
}

char		*handle_flags(t_res *res, va_list ap, t_args *mod, char *spec)
{
	if (*spec == '*' || *spec == '.')
		spec = width_prec(ap, mod, spec);
	else if (*spec == '-')
	{
		mod->align = 1;
		mod->pad = ' ';
	}
	else if (*spec == '0' && mod->align == 0 && mod->prec == -1)
		mod->pad = '0';
	else if ((*spec == ' ' || *spec == '+') && mod->pre != '+')
		mod->pre = *spec;
	else if (*spec == '#')
		mod->hash = 4;
	else if (*spec >= '1' && *spec <= '9')
	{
		mod->width = ft_atoi(spec);
		while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
			spec++;
	}
	else if (*spec == '{')
		spec = colors(res, spec);
	return (spec + 1);
}

char		*width_prec(va_list ap, t_args *mod, char *spec)
{
	if (*spec == '*')
	{
		mod->width = va_arg(ap, int);
		if (mod->width < 0)
		{
			mod->width = mod->width * -1;
			mod->align = 1;
		}
	}
	else if (*spec == '.')
	{
		if (*(spec + 1) == '*')
		{
			mod->prec = va_arg(ap, unsigned int);
			spec++;
		}
		else
		{
			mod->prec = ft_atoi(spec + 1);
			while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
				spec++;
		}
	}
	return (spec);
}

char	g_colors[34][2][15] = {
	{"{red}", "\033[31m"},
	{"{bred}", "\033[31;1m"},
	{"{green}", "\033[32m"},
	{"{bgreen}", "\033[32;1m"},
	{"{yellow}", "\033[33m"},
	{"{byellow}", "\033[33;1m"},
	{"{blue}", "\033[34m"},
	{"{bblue}", "\033[34;1m"},
	{"{purple}", "\033[35m"},
	{"{bpurple}", "\033[35;1m"},
	{"{cyan}", "\033[36m"},
	{"{bcyan}", "\033[36;1m"},
	{"{black}", "\033[30m"},
	{"{bblack}", "\033[30;1m"},
	{"{white}", "\033[37m"},
	{"{bwhite}", "\033[37;1m"},
	{"{b_red}", "\033[41m"},
	{"{b_bred}", "\033[41;1m"},
	{"{b_green}", "\033[42m"},
	{"{b_bgreen}", "\033[42;1m"},
	{"{b_yellow}", "\033[43m"},
	{"{b_byellow}", "\033[43;1m"},
	{"{b_blue}", "\033[44m"},
	{"{b_bblue}", "\033[44;1m"},
	{"{b_purple}", "\033[45m"},
	{"{b_bpurple}", "\033[45;1m"},
	{"{b_cyan}", "\033[46m"},
	{"{b_bcyan}", "\033[46;1m"},
	{"{b_black}", "\033[40m"},
	{"{b_bblack}", "\033[40;1m"},
	{"{b_white}", "\033[47m"},
	{"{b_bwhite}", "\033[47;1m"},
	{"{eoc}", "\033[0m"},
	{"{noc}", "\033[0m"}};

char		*colors(t_res *res, char *spec)
{
	int		i;
	int		len0;
	int		len1;

	i = 0;
	while (i < 34)
	{
		len0 = ft_strlen(g_colors[i][0]);
		if (ft_strncmp(spec, g_colors[i][0], len0) == 0)
		{
			len1 = ft_strlen(g_colors[i][1]);
			check_res(res, len1);
			ft_strcat(res->out, g_colors[i][1]);
			res->len += len1;
			return (spec + len0 - 1);
		}
		i++;
	}
	return (spec + 1);
}
