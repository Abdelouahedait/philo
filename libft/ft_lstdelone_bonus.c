/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:58:33 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/20 22:28:33 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst -> content);
		free(lst);
	}
}
/*
void	del(void *content)
{
	free(content);
}

int main()
{
	t_list *list = s;
	t_list *s = ft_lstnew("zero");
	ft_lstdelone(s, del);
}*/
