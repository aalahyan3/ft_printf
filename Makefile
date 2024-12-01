# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 17:58:06 by aalahyan          #+#    #+#              #
#    Updated: 2024/11/30 17:24:58 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

CFLAGS= -Wall -Wextra -Werror

SRCSIDR= srcs

BONUS_DIR=srcs_bonus

INCLUDESDIR=includes

HEADERFILE=$(INCLUDESDIR)/ft_printf.h

CFILES_BONUS =$(BONUS_DIR)/ft_printf_bonus.c\
		$(BONUS_DIR)/utils_printf_bonus.c\
		$(BONUS_DIR)/pf_putchar_bonus.c\
		$(BONUS_DIR)/print_character_bonus.c\
		$(BONUS_DIR)/print_string_bonus.c\
		$(BONUS_DIR)/print_signed_number_bonus.c\
		$(BONUS_DIR)/utils_printf_2_bonus.c\
		$(BONUS_DIR)/print_unsigned_number_bonus.c\
		$(BONUS_DIR)/print_hex_number_bonus.c\
		$(BONUS_DIR)/print_adress_bonus.c\
		$(BONUS_DIR)/libft_functions_bonus.c

CFILES =$(SRCSIDR)/ft_printf.c\
		$(SRCSIDR)/utils_printf.c\
		$(SRCSIDR)/pf_putchar.c\
		$(SRCSIDR)/print_string.c\
		$(SRCSIDR)/print_signed_number.c\
		$(SRCSIDR)/print_unsigned_number.c\
		$(SRCSIDR)/print_hex_number.c\
		$(SRCSIDR)/print_adress.c\
		$(SRCSIDR)/libft_functions.c

OFILES= $(CFILES:.c=.o)
BONUSOFILES= $(CFILES_BONUS:.c=.o)

NAME=libftprintf.a

all: .mandatory $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $^
bonus: .bonus

%.o: %.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@
	
.mandatory:
	rm -rf $(NAME) .bonus
	touch $@

.bonus: $(BONUSOFILES)
	rm -rf $(NAME) .mandatory
	ar rcs $(NAME) $^
	touch $@


clean:
	rm -f $(OFILES) $(BONUSOFILES) .bonus .mandatory

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean re clean