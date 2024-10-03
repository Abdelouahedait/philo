#include "philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!cheak_dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}


void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}


void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}
// void eat(t_philo *philo)
// {
//     pthread_mutex_t *first_fork;
//     pthread_mutex_t *second_fork;

//     // if (philo->id % 2 == 0) {
//         first_fork = philo->r_fork;
//         second_fork = philo->l_fork;
//     // } else {
//     //     first_fork = philo->l_fork;
//     //     second_fork  = philo->r_fork;
//     // }
//     if (pthread_mutex_lock(first_fork) != 0) 
//         return;
//     print_message("has taken a fork", philo, philo->id);
//     if (philo->num_of_philos == 1)
//     {
//         ft_usleep(philo->time_to_die);
//         pthread_mutex_unlock(first_fork);
//         return;
//     }
//     if (pthread_mutex_lock(second_fork) != 0)
//     {
//         pthread_mutex_unlock(first_fork);
//         return;
//     }
//     print_message("has taken a fork", philo, philo->id);
//     philo->eating = 1;
//     print_message("is eating", philo, philo->id);
//     if (pthread_mutex_lock(philo->meal_lock) == 0)
//     {
//         philo->last_meal = get_current_time();
//         philo->meals_eaten++;
//         pthread_mutex_unlock(philo->meal_lock);
//     }
//     else
//     {
//         philo->eating = 0;
//         pthread_mutex_unlock(first_fork);
//         pthread_mutex_unlock(second_fork);
//         return;
//     }
//     ft_usleep(philo->time_to_eat);
//     philo->eating = 0;
//     pthread_mutex_unlock(first_fork);
//     pthread_mutex_unlock(second_fork);
// }



void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
