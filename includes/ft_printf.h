/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:47 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 16:20:40 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

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
void	manage_format(va_list args, char *format, int *counter);
void	print_string(char *str, int *counter);
void	print_signed_number(int n, int *counter);
void	print_unsigned_number(unsigned int n, int *counter);
void	print_hex_number(unsigned int n, int *counter, char type);
void	print_adress(void *ptr, int *counter);
int		is_format(char c);
void	reset_flags(t_flags *flags);
void	manage_format_bonus(va_list args, t_flags *flags, \
						char *specifier, int *counter);
void	manage_flags_2(t_flags *flags, char *format);
void	manage_flags(va_list args, t_flags *flags, char *format, int *counter);
void	pf_putchar(char c, int *counter);
void	print_character_bonus(char c, t_flags *flags, int *counter);
void	print_string_bonus(char *str, t_flags *flags, int *counter);
void	reverse_string(char *str, int len);
void	print_signed_number_bonus(int n, t_flags *flags, int *counter);
void	print_unsigned_number_bonus(unsigned int n, \
t_flags *flags, int *counter);
void	print_hex_number_bonus(unsigned int n, t_flags *flags, int *counter, \
char type);
void	print_adress_bonus(void *ptr, t_flags *flags, int *counter);
void	print_persent(t_flags *flags, int *counter);
int		is_flag(char c);
void	print_invalid_flag(char *str, int *counter);
void	get_pad_and_zeros_int(t_flags *flags, int *pad, \
int *zer, int len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

void	manage_format(va_list args, char *format, int *counter);
void	print_string(char *str, int *counter);
void	print_signed_number(int n, int *counter);
void	print_unsigned_number(unsigned int n, int *counter);
void	print_hex_number(unsigned int n, int *counter, char type);
void	print_adress(void *ptr, int *counter);
#endif