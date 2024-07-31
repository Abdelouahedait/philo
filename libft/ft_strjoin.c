/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:42:53 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/12 22:18:03 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strs;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strs = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strs)
		return (NULL);
	ft_memcpy(strs, s1, len1);
	ft_memcpy(strs + len1, s2, len2);
	strs[len1 + len2] = '\0';
	return (strs);
}
