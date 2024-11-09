/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:33 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/09 16:20:41 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//Warning !: the folowing function does not work 
//with read-only strings. be careful
void	reverse_string(char *str, int len)
{
	char	temp;
	int		i;

	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

int	is_flag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

void	print_invalid_flag(char *str, int *counter)
{
	while (*str && !is_format(*str))
		pf_putchar(*str++, counter);
	if (is_format(*str))
		pf_putchar(*str, counter);
}

void	print_persent(t_flags *flags, int *counter)
{
	int	padding;

	padding = 0;
	if (flags->field_w > 1)
		padding = flags->field_w - 1;
	if (flags->left_alig == 1)
	{
		pf_putchar('%', counter);
		while (padding--)
			pf_putchar(' ', counter);
	}
	else
	{
		while (padding--)
			pf_putchar(' ', counter);
		pf_putchar('%', counter);
	}
}
