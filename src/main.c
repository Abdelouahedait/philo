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
	return(1);

}

int main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if ((ac != 6 || ac != 5) )
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
}