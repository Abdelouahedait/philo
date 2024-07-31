/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:20 by a-ait-bo          #+#    #+#             */
/*   Updated: 2023/11/12 21:35:45 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
/*
int main ()
{
	int fd = open("fo.txt", O_WRONLY  | O_CREAT ); 

	ft_putnbr_fd(-2147483648, fd);
}*/
