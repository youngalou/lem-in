# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 10:39:14 by lyoung            #+#    #+#              #
#    Updated: 2017/09/11 11:10:00 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAG = -Wall -Wextra -Werror

LIBFT = ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strndup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strnjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   count_words.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_isspace.c \
	   ft_bzero.c \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_abs.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_atoi.c \
	   ft_atoi_base.c \
	   ft_itoa.c \
	   ft_itoa_base.c \
	   ft_uinttoa_base.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \

GET_NEXT_LINE = get_next_line.c

FT_PRINTF = ft_printf.c \
			ft_vprintf.c \
			build.c \
			modifiers.c \
			conversions.c \
			handle_length.c \
			handle_diuox.c \
			handle_scp.c \
			handle_extra.c \

FILES = $(addprefix libft/, $(LIBFT)) \
		$(addprefix get_next_line/, $(GET_NEXT_LINE)) \
		$(addprefix ft_printf/, $(FT_PRINTF)) \

SRCS = $(addprefix src/, $(FILES))

OBJS = *.o \

all: $(NAME)

$(NAME):
	@gcc $(CFLAG) -c $(SRCS)
	@echo "\033[32m- $(NAME) object files created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@echo "\033[32m- $(NAME) compiled\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[31m- $(NAME) object files removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m- $(NAME) removed\033[0m"

re: fclean all
