/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:36:48 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 17:07:58 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_unsigned_number(unsigned int n, int *counter)
{
	char	decimal[11];
	char	buffer[11];
	int		i;

	i = 0;
	ft_strlcpy(decimal, "0123456789", 11);
	if (n == 0)
		buffer[i++] = '0';
	while (n)
	{
		buffer[i++] = decimal[n % 10];
		n /= 10;
	}
	buffer[i] = 0;
	i--;
	while (i >= 0)
		pf_putchar(buffer[i--], counter);
}
