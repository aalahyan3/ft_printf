/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:28:47 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 15:43:21 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hex_number(unsigned int n, int *counter, char type)
{
	char	hex[17];
	char	buffer[17];
	int		i;

	i = 0;
	if (type == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	else
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	if (n == 0)
		buffer[i++] = '0';
	while (n)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	buffer[i] = 0;
	i--;
	while (i >= 0)
		pf_putchar(buffer[i--], counter);
}
