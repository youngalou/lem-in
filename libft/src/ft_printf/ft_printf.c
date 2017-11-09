/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:43:40 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	len = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return (len);
}

int		ft_snprintf(char *ret, size_t size, const char *fmt, ...)
{
	va_list		ap;
	char		*tmp;
	size_t		len;

	if (!fmt || !*fmt || size - 1 == 0)
	{
		*ret = 0;
		return (0);
	}
	tmp = NULL;
	va_start(ap, fmt);
	len = ft_vsprintf(tmp, fmt, ap);
	ft_strncpy(ret, tmp, (len < size - 1) ? len : size - 1);
	va_end(ap);
	return ((int)len);
}

int		ft_sprintf(char *ret, const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (!fmt || !*fmt)
	{
		*ret = 0;
		return (0);
	}
	va_start(ap, fmt);
	len = ft_vsprintf(ret, fmt, ap);
	va_end(ap);
	return (len);
}

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	len = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	len = ft_vprintf(fmt, ap);
	va_end(ap);
	return (len);
}
