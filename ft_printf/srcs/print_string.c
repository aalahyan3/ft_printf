/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:06:38 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/08 17:20:33 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	pf_putstr(char *str, int *counter, int len)
{
	while (len--)
	{
		pf_putchar(*str++, counter);
		if (*counter == -1)
			return ;
	}
}

static void	print_left_alig(char *str, t_flags *flags, int *counter, int len)
{
	int	padding;

	padding = 0;
	if (flags->precision < len && flags->precision >= 0)
		len = flags->precision;
	if (flags->field_w > len)
		padding = flags->field_w - len;
	pf_putstr(str, counter, len);
	if (*counter == -1)
		return ;
	while (padding--)
	{
		pf_putchar(' ', counter);
		if (*counter == -1)
			return ;
	}
}

static void	print_right_alig(char *str, t_flags *flags, int *counter, int len)
{
	int	padding;

	padding = 0;
	if (flags->precision < len && flags->precision >= 0)
		len = flags->precision;
	if (flags->field_w > len)
		padding = flags->field_w - len;
	while (padding--)
	{
		pf_putchar(' ', counter);
		if (*counter == -1)
			return ;
	}
	pf_putstr(str, counter, len);
	if (*counter == -1)
		return ;
}

void	print_string(char *str, t_flags *flags, int *counter)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->left_alig == 1)
		print_left_alig(str, flags, counter, len);
	else
		print_right_alig(str, flags, counter, len);
}
