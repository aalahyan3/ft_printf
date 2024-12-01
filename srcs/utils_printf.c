/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:33:29 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 15:42:14 by aalahyan         ###   ########.fr       */
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

void	manage_format(va_list args, char *format, int *counter)
{
	if (format[0] == 'c')
		pf_putchar(va_arg(args, int), counter);
	else if (format[0] == 's')
		print_string(va_arg(args, char *), counter);
	else if (format[0] == 'd' || format[0] == 'i')
		print_signed_number(va_arg(args, int), counter);
	else if (format[0] == 'u')
		print_unsigned_number(va_arg(args, unsigned int), counter);
	else if (format[0] == 'x' || format[0] == 'X')
		print_hex_number(va_arg(args, unsigned int), counter, format[0]);
	else if (format[0] == 'p')
		print_adress(va_arg(args, void *), counter);
	else if (format[0] == '%')
		pf_putchar('%', counter);
}
