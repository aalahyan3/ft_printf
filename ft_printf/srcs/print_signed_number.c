/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:35 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/09 17:50:06 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_right_alig(char *str, t_flags *flags, int *counter, int len)
{
	int	zeros;
	int	padding;

	zeros = 0;
	padding = 0;
	if (flags->precision > len)
		zeros = flags->precision - len;
	else if (flags->zero_pad == 1 && flags->precision == -1)
		zeros = flags->field_w - len;
	if (flags->field_w > len)
		padding = flags->field_w - len - zeros;
	while (padding--)
	{
		pf_putchar(' ', counter);
	}
	if (flags->plus == 1 && str[0] != '-')
		pf_putchar('+', counter);
	else if (flags->space == 1 && str[0] != '-')
		pf_putchar(' ', counter);
	while (zeros--)
		pf_putchar('0', counter);
	while (*str)
		pf_putchar(*str++, counter);
}

static void	print_left_alig(char *str, t_flags *flags, int *counter, int len)
{
	int	zeros;
	int	padding;

	padding = 0;
	zeros = 0;
	if (flags->precision > len)
		zeros = flags->precision - len;
	else if (flags->zero_pad == 1 && flags->precision == -1)
		zeros = flags->field_w - len;
	if (flags->field_w > len)
		padding = flags->field_w - len - zeros;
	if (flags->plus == 1 && str[0] != '-')
		pf_putchar('+', counter);
	else if (flags->space == 1 && str[0] != '-')
		pf_putchar(' ', counter);
	while (zeros--)
		pf_putchar('0', counter);
	while (*str)
		pf_putchar(*str++, counter);
	while (padding--)
		pf_putchar(' ', counter);
}

static void	print_signed_number_2(char *str, t_flags *flags, \
int *counter, int len)
{
	if ((flags->plus == 1 || flags->space == 1) && str[0] != '-')
		flags->field_w = flags->field_w - 1;
	if (flags->right_alig == 1)
		print_right_alig(str, flags, counter, len);
	else
		print_left_alig(str, flags, counter, len);
}

void	print_signed_number(int n, t_flags *flags, int *counter)
{
	char	buffer[12];
	int		i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (nb == 0)
		buffer[i++] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		buffer[i++] = '-';
	buffer[i] = 0;
	reverse_string(buffer, i);
	print_signed_number_2(buffer, flags, counter, i);
}
