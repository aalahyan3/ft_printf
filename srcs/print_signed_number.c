/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:35 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 15:49:33 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_signed_number(int n, int *counter)
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
	i--;
	while (i >= 0)
		pf_putchar(buffer[i--], counter);
}
