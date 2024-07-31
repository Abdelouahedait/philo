/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:57:17 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/22 18:09:52 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_word(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			i++;
			j = 1;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static void	free_str(char **result, int word)
{
	while (word++)
		free(result[word]);
	free(result);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == c || s[j] == 0)
			i = j + 1;
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (j - i + 2));
			if (!result[word])
			{
				free_str(result, word);
				return (0);
			}
			ft_strlcpy(result[word], (s + i), j - i + 2);
			word++;
		}
		j++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (cont_word(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}
