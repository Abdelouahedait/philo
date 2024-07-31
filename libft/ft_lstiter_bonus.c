/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:58:45 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/16 17:58:47 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
void f(void *content)
{
    ((char *)content)[0] = ((char *)content)[0] + 1;
    printf("%s", (char *)content);
}

int main()
{
    char st[] = "hi";
     
    t_list *s = ft_lstnew(st);
    (char *)ft_lstiter(s, f);

    free(s);
    return 0;
}*/
