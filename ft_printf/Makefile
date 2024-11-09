# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 17:58:06 by aalahyan          #+#    #+#              #
#    Updated: 2024/11/09 16:12:30 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= 
SRCSIDR= srcs
LIBFTDIR=libft
INCLUDESDIR=includes
HEADERFILE=$(INCLUDESDIR)/ft_printf.h
CFILES =$(SRCSIDR)/ft_printf.c\
		$(SRCSIDR)/utils_printf.c\
		$(SRCSIDR)/pf_putchar.c\
		$(SRCSIDR)/print_character.c\
		$(SRCSIDR)/print_string.c\
		$(SRCSIDR)/print_signed_number.c\
		$(SRCSIDR)/utils_printf_2.c\
		$(SRCSIDR)/print_unsigned_number.c\
		$(SRCSIDR)/print_hex_number.c\
		$(SRCSIDR)/print_adress.c
OFILES= $(CFILES:.c=.o)

LIBFT=$(LIBFTDIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

$(LIBFT):
	make -C libft

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) $(LIBFT)
		