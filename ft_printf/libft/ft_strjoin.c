/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:43:07 by aalahyan          #+#    #+#             */
/*   Updated: 2024/10/28 22:03:46 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	char	*ptr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_string = malloc(sizeof(char) * size);
	if (!joined_string)
		return (NULL);
	ptr = joined_string;
	while (*s1)
		*joined_string++ = *s1++;
	while (*s2)
		*joined_string++ = *s2++;
	*joined_string = 0;
	return (ptr);
}