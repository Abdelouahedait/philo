#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include "../libft/libft.h"
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;


/*init.c*/
void	init_input(t_philo *philo, char **s);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
		char **str);
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_num);
/*-----------*/

/*thread.c*/
int		cheak_dead(t_philo *philo);
void	*routine_fun(void *pointer);
int		thread_create(t_program *program, pthread_mutex_t *forks);
/*-----------*/

/*utils.c*/
void	destory_all(char *str, t_program *program, pthread_mutex_t *forks);
int	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
/*-----------*/


/*routine.c*/
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);
void	print_message(char *str, t_philo *philo, int id);
/*-----------*/

/*observer.c*/
int	check_if_dead(t_philo *philos);
int	philosopher_dead(t_philo *philo, size_t time_to_die);

int	check_if_all_ate(t_philo *philos);
void	*monitor(void *pointer);
/*-----------*/

#endif