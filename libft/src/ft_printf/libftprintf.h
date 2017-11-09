/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:44:15 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 15:45:07 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include "../libft/libft.h"

# define F_SCP (*spec == 's' || *spec == 'c' || *spec == 'C' || *spec == 'p')
# define F_DI (*spec == 'd' || *spec == 'D' || *spec == 'i')
# define F_UOX (*spec == 'u' || *spec == 'o' || *spec == 'x' || *spec == 'X')
# define F_CAPS (*spec == 'D' || *spec == 'U' || *spec == 'O')
# define F_CONV (F_SCP || F_DI || F_UOX || F_CAPS || *spec == '%')

# define F_HL (*spec == 'h' || *spec == 'l' || *spec == 'L')
# define F_ZJ (*spec == 'z' || *spec == 'j')
# define F_LEN (F_HL || F_ZJ)

# define F_WP (*spec == '.' || *spec == '*' || (*spec >= '0' && *spec <= '9'))
# define F_PRE (*spec == '-' || *spec == '+' || *spec == ' ' || *spec == '#')
# define F_FLAGS (F_WP || F_PRE || *spec == '{')

# define F_MOD (F_LEN || F_FLAGS)

/*
** hh = 1	:	unsigned char
** h  = 2	:	unsigned short
** l  = 3	:	long
** ll = 4	:	long long
** z  = 5	:	size_t
** j  = 6	:	intmax_t
*/

typedef struct	s_args
{
	int			length;
	intmax_t	width;
	int			prec;
	int			align;
	char		pad;
	char		pre;
	int			base;
	int			hash;
	int			addr;
	char		*tmp;
}				t_args;

typedef struct	s_res
{
	char		*out;
	size_t		len;
	size_t		cap;
	size_t		size;
	char		*start;
	char		*fmt;
	char		*place;
}				t_res;

/*
** --------------- ft_printf.c --------------
*/

int				ft_asprintf(char **ret, const char *fmt, ...);
int				ft_snprintf(char *ret, size_t size, const char *fmt, ...);
int				ft_sprintf(char *ret, const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_printf(const char *fmt, ...);

/*
** --------------- ft_vprintf.c --------------
*/

int				ft_vasprintf(char **ret, const char *fmt, va_list ap);
int				ft_vsprintf(char *ret, const char *fmt, va_list ap);
int				ft_vdprintf(int fd, const char *fmt, va_list ap);
int				ft_vprintf(const char *fmt, va_list ap);

/*
** --------------- build.c --------------
*/

t_res			*init_res(size_t cap);
int				resize_res(t_res *res, size_t size);
void			check_res(t_res *res, size_t size);
void			free_res(t_res *res);

/*
** --------------- conversions.c --------------
*/

char			*handle_args(t_res *res, va_list ap, t_args *mod);
char			*conversions(t_res *res, va_list ap, t_args *mod, char *spec);
char			*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec);
void			replace_null(t_res *res);

/*
** --------------- modifiers.c --------------
*/

void			init_mods(t_args *mod);
char			*search_mods(t_res *res, va_list ap, t_args *mod, char *spec);
char			*handle_flags(t_res *res, va_list ap, t_args *mod, char *spec);
char			*width_prec(va_list ap, t_args *mod, char *spec);
char			*colors(t_res *res, char *spec);

/*
** --------------- handle_length.c --------------
*/

char			*handle_length(t_args *mod, char *spec);
intmax_t		uox_len(va_list ap, t_args *mod);
intmax_t		di_len(va_list ap, t_args *mod);

/*
** --------------- handle_diuox.c --------------
*/

char			*handle_diuox(t_res *res, va_list ap, t_args *mod, char *spec);
char			*uox_conv(va_list ap, t_args *mod, char *spec, char *s);
char			*diuox_prec(char *s, int len, t_args *mod);

/*
** --------------- handle_scp.c --------------
*/

char			*handle_scp(t_res *res, va_list ap, t_args *mod, char *spec);
char			*char_conv(t_res *res, va_list ap, t_args *mod);
char			*pointer_conv(va_list ap, t_args *mod);
char			*string_prec(char *s, t_args *mod);

/*
** --------------- handle_extra.c --------------
*/

char			*add_padding(char *s, int len, t_args *mod);
char			*add_prefix(char *s, t_args *mod);
char			*move_prefix(t_args *mod);
char			*add_hash(char *s, t_args *mod);

#endif
