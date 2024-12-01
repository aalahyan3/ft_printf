/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:06:38 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/30 17:07:54 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_string(char *str, int *counter)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	while (*str)
		pf_putchar(*str++, counter);
}
