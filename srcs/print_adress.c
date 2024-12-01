/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:12:13 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:03 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_ox(int *counter)
{
	pf_putchar('0', counter);
	pf_putchar('x', counter);
}

void	print_adress(void *ptr, int *counter)
{
	unsigned long	addr;
	int				i;
	char			hex[17];
	char			buff[17];

	addr = (unsigned long)ptr;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	i = 0;
	if (addr == 0)
		buff[i++] = '0';
	while (addr)
	{
		buff[i++] = hex[addr % 16];
		addr /= 16;
	}
	buff[i] = 0;
	print_ox(counter);
	i--;
	while (i >= 0)
		pf_putchar(buff[i--], counter);
}
