/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:00:15 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/08 16:55:52 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_padding(int fwd)
{
	if (fwd > 1)
		return (fwd - 1);
	else
		return (0);
}

void	print_character(char c, t_flags *flags, int *counter)
{
	int	padding;

	padding = get_padding(flags->field_w);
	if (flags->left_alig == 1)
	{
		pf_putchar(c, counter);
		while (padding--)
		{
			pf_putchar(' ', counter);
			if ((*counter) == -1)
				return ;
		}
	}
	if (flags->right_alig == 1)
	{
		while (padding--)
		{
			pf_putchar(' ', counter);
			if ((*counter) == -1)
				return ;
		}
		pf_putchar(c, counter);
		if ((*counter) == -1)
			return ;
	}
}
