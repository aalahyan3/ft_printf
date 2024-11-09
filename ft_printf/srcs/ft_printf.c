/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:19 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/09 16:12:18 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	t_flags	flags;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format && *format != '%')
			pf_putchar(*format++, &counter);
		if (*format && *format == '%')
		{
			format++;
			reset_flags(&flags);
			manage_flags(args, &flags, (char *)(format), &counter);
			if (counter == -1)
				return (-1);
			while (*format && !is_format(*format))
				format++;
		}
		if (*format)
			format++;
	}
	va_end(args);
	return (counter);
}
