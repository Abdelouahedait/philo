/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:04:33 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/20 22:36:55 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	len_s;
	size_t	size;

	size = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start < len_s)
		size = len_s - start;
	if (size > len)
		size = len;
	subs = malloc((size + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (size > i && start < len_s)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}
