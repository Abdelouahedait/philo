/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-ait-bo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:06:44 by a-ait-bo          #+#    #+#             */
/*   Updated: 2024/10/03 12:06:46 by a-ait-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_param(char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!ft_strchr("0123456789", s[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if ((ac != 6 && ac != 5) || ft_atoi(av[1]) > 200 || !check_param(av))
		return (printf("(^_^) \033[0;31m(Error) \033[0m(*_*)\n"), 0);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
	thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
