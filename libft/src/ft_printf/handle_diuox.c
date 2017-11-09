/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diuox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:46:06 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:43:55 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_diuox(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (F_DI)
	{
		s = ft_itoa(di_len(ap, mod));
		res->size = ft_strlen(s);
		if (*s == '-')
		{
			mod->pre = '-';
			res->size--;
		}
		s = add_prefix((diuox_prec(s, mod->prec - res->size, mod)), mod);
	}
	else if (F_UOX || F_CAPS)
	{
		s = uox_conv(ap, mod, spec, s);
		s = add_hash(diuox_prec(s, mod->prec - ft_strlen(s), mod), mod);
	}
	return (s);
}

char	*uox_conv(va_list ap, t_args *mod, char *spec, char *s)
{
	int		i;

	if (*spec == 'u' || *spec == 'U')
		mod->base = 10;
	else if (*spec == 'o' || *spec == 'O')
	{
		mod->base = 8;
		(mod->hash) ? mod->hash = 1 : 0;
	}
	else if (*spec == 'x' || *spec == 'X')
	{
		mod->base = 16;
		(mod->hash) ? mod->hash = 2 : 0;
	}
	s = ft_uinttoa_base(uox_len(ap, mod), mod->base);
	if (*spec == 'X' && *s != '0')
	{
		(mod->hash) ? mod->hash = 3 : 0;
		i = -1;
		while (s[++i])
			s[i] = ft_toupper(s[i]);
	}
	return (s);
}

char	*diuox_prec(char *s, int len, t_args *mod)
{
	char	*padding;
	char	*tmp;
	char	pre[2];

	(mod->hash == 1) ? len-- : 0;
	if (*s == '0' && mod->hash != 1)
		s = string_prec(s, mod);
	if (len < 1)
		return (s);
	pre[0] = mod->pre;
	pre[1] = '\0';
	(mod->pre == '-') ? s++ : 0;
	padding = (char*)malloc(len + 1);
	padding[len] = '\0';
	while (--len >= 0)
		padding[len] = '0';
	tmp = ft_strjoin(padding, s);
	(mod->pre == '-') ? s-- : 0;
	ft_strdel(&s);
	s = tmp;
	if (pre[0] == '-')
		tmp = ft_strjoin(pre, s);
	s = tmp;
	ft_strdel(&padding);
	return (s);
}
