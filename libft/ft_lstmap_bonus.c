/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:13:50 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/19 21:32:32 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_node;
	void	*ptr;

	new = NULL;
	while (lst)
	{
		ptr = f(lst -> content);
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			ft_lstclear(&new, del);
			free(ptr);
			break ;
		}
		ft_lstadd_back(&new, new_node);
		lst = lst->next;
	}
	return (new);
}
/*
void	del(void *content)
{
	free(content);
}

void *f(void *content)
{
    ((char *)content)[0] = ((char *)content)[0] + 1;
    printf("%s", (char *)content);
	return (content);
}

int	main()
{
	char st[] = "hi";
	t_list *s = ft_lstnew(st);
	ft_lstmap(s, f, del);
}*/
