/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:47 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/13 16:43:38 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	field_w;
	int	left_alig;
	int	right_alig;
	int	precision;
	int	zero_pad;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *format, ...);
int		is_format(char c);
void	reset_flags(t_flags *flags);
void	manage_format(va_list args, t_flags *flags, \
						char *specifier, int *counter);
void	manage_flags_2(t_flags *flags, char *format);
void	manage_flags(va_list args, t_flags *flags, char *format, int *counter);
void	pf_putchar(char c, int *counter);
void	print_character(char c, t_flags *flags, int *counter);
void	print_string(char *str, t_flags *flags, int *counter);
void	reverse_string(char *str, int len);
void	print_signed_number(int n, t_flags *flags, int *counter);
void	print_unsigned_number(unsigned int n, t_flags *flags, int *counter);
void	print_hex_number(unsigned int n, t_flags *flags, int *counter, \
char type);
void	print_adress(void *ptr, t_flags *flags, int *counter);
void	print_persent(t_flags *flags, int *counter);
int		is_flag(char c);
void	print_invalid_flag(char *str, int *counter);
void	get_pad_and_zeros_int(t_flags *flags, int *pad, int *zer, int len);
#endif