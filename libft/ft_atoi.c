/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:55:49 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/13 14:55:52 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dijit(const char *s, long int sing)
{
	long int	i;
	long int	j;
	long int	k;

	i = 0;
	j = 0;
	while (ft_isdigit(s[i]) == 1)
	{
		k = j;
		j = (10 * j) + s[i] - '0';
		if (j < k)
		{
			if (sing == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	long int	j;
	long int	sing;

	sing = 1;
	j = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sing *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	j = dijit(str, sing);
	return (j * sing);
}
