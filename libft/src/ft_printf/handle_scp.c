/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:14:23 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:44:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_scp(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (*spec == 's' || *spec == 'S')
	{
		if (!(s = va_arg(ap, char*)))
			s = ft_strdup("(null)");
		else
			s = ft_strdup(s);
		s = string_prec(s, mod);
		mod->prec = -1;
	}
	else if (*spec == 'c' || *spec == 'C')
		s = char_conv(res, ap, mod);
	else if (*spec == 'p')
		s = pointer_conv(ap, mod);
	return (s);
}

char	*char_conv(t_res *res, va_list ap, t_args *mod)
{
	char	*s;

	s = ft_strnew(2);
	s[0] = va_arg(ap, int);
	if (s[0] == 0)
		s[0] = 127;
	if (!s[0])
		res->len++;
	mod->prec = -1;
	return (s);
}

char	*pointer_conv(va_list ap, t_args *mod)
{
	char	*s;

	mod->hash = 2;
	mod->addr = 1;
	s = ft_itoa_base(va_arg(ap, intmax_t), 16);
	s = diuox_prec(s, mod->prec - ft_strlen(s), mod);
	if (ft_strcmp(s, "0") == 0 && mod->prec != -1)
		s = ft_strdup("\0");
	s = add_hash(s, mod);
	return (s);
}

char	*string_prec(char *s, t_args *mod)
{
	char	*tmp;

	if (mod->prec < 0)
		return (s);
	tmp = ft_strndup(s, mod->prec);
	ft_strdel(&s);
	return (tmp);
}
