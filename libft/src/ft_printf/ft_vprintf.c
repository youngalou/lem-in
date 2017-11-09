/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:48:28 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:43:46 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	va_list		clone;
	t_res		*res;
	t_args		*mod;
	size_t		len;

	va_copy(clone, ap);
	res = init_res(50);
	mod = (t_args*)malloc(sizeof(t_args));
	res->start = ft_strdup(fmt);
	res->fmt = res->start;
	while ((res->place = ft_strchr(res->fmt, '%')))
		res->fmt = handle_args(res, clone, mod);
	if (ft_strlen(res->fmt))
	{
		ft_strcat(res->out, res->fmt);
		res->len += ft_strlen(res->fmt);
	}
	replace_null(res);
	len = res->len;
	*ret = ft_strndup(res->out, len);
	free_res(res);
	free(mod);
	va_end(clone);
	return (len);
}

int		ft_vsprintf(char *ret, const char *fmt, va_list ap)
{
	char		*tmp;
	int			len;

	if (!fmt || !*fmt)
	{
		*ret = 0;
		return (0);
	}
	len = ft_vasprintf(&tmp, fmt, ap);
	ft_strncpy(ret, tmp, len);
	ft_strdel(&tmp);
	return (len);
}

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	char		*out;
	int			len;

	len = ft_vasprintf(&out, fmt, ap);
	write(fd, out, len);
	ft_strdel(&out);
	return (len);
}

int		ft_vprintf(const char *fmt, va_list ap)
{
	char		*out;
	int			len;

	if (!fmt | !*fmt)
		return (0);
	len = ft_vasprintf(&out, fmt, ap);
	write(1, out, len);
	ft_strdel(&out);
	return (len);
}
