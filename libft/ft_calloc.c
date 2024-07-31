/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:54:42 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/27 18:46:58 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	a;

	a = count * size;
	if (a > 0)
	{
		if (count > SIZE_MAX / size)
			return (NULL);
		s = (void *)malloc(count * size);
		if (!s)
			return (NULL);
		ft_bzero(s, (count * size));
		return ((void *)s);
	}
	s = (void *)malloc(1);
	if (!s)
		return (NULL);
	ft_bzero(s, 1);
	return ((void *)s);
}
