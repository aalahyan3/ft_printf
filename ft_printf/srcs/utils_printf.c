/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:33:29 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/09 16:08:07 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || \
		c == 'i' || c == 'u' || c == 'p' || \
		c == '%' || c == 'x' || c == 'X')
	{
		return (1);
	}
	else
		return (0);
}

void	reset_flags(t_flags *flags)
{
	flags->field_w = 0;
	flags->hash = 0;
	flags->right_alig = 1;
	flags->left_alig = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero_pad = 0;
	flags->precision = -1;
}

void	manage_flags(va_list args, t_flags *flags, char *format, int *counter)
{
	int	i;

	i = 0;
	while (format[i] && is_flag(format[i]))
	{
		if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == '-')
		{
			flags->right_alig = 0;
			flags->left_alig = 1;
		}
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '0')
			flags->zero_pad = 1;
		i++;
	}
	i += manage_flags_2(flags, format + i);
	manage_format(args, flags, format + i, counter);
}

int	manage_flags_2(t_flags *flags, char *format)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
			flags->field_w = flags->field_w * 10 + (format[i++] - '0');
	}
	if (format[i] == '.')
	{
		i++;
		flags->precision = 0;
		while (ft_isdigit(format[i]))
			flags->precision = flags->precision * 10 + (format[i++] - '0');
	}
	return (i);
}

void	manage_format(va_list args, t_flags *flags, char *\
format, int *counter)
{
	if (format[0] == 'c')
		print_character(va_arg(args, int), flags, counter);
	else if (format[0] == 's')
		print_string(va_arg(args, char *), flags, counter);
	else if (format[0] == 'd' || format[0] == 'i')
		print_signed_number(va_arg(args, int), flags, counter);
	else if (format[0] == 'u')
		print_unsigned_number(va_arg(args, unsigned int), flags, counter);
	else if (format[0] == 'x' || format[0] == 'X')
		print_hex_number(va_arg(args, unsigned int), flags, counter, format[0]);
	else if (format[0] == 'p')
		print_adress(va_arg(args, void *), flags, counter);
	else if (format[0] == '%')
		print_persent(flags, counter);
	else
		print_invalid_flag(format, counter);
}