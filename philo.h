/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:16:27 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/19 18:31:36 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define EINVAL 1
# define EDEADLK 2
# define EPERM 3
# define ENOMEM 4
# define EBUSY 5
# define EAGAIN 6
# define ESRCH 7

typedef struct s_info	t_info;

typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	CREATE,
	JOIN,
	DETACH,
	DESTROY,
}						t_code;

typedef enum e_time
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}						t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKEN_FIRST_FORK,
	TAKEN_SECOND_FORK,
	DIED,
}						t_philo_status;

// boolean
typedef enum e_bool
{
	false,
	true,
}						t_bool;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_counter;
	t_bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t thread_id; // a philo ia a thread
	pthread_mutex_t		philo_mutex;
	t_info				*infos;
	//	nbr_meals;
}						t_philo;

typedef struct s_info
{
	long				philo_nbr;
	long				tt_die;
	long				tt_eat;
	long				tt_sleep;
	long nbr_limit_meals; // if does not have the nbr of meals will be -1
	long				start_routine;
	long				threads_running_n;
	t_bool				all_philo_created;
	t_bool end_routine; // if a philo dies or all of them have eaten
	pthread_t			monitor;
	pthread_mutex_t info_mutex; // avoid races while reading from infos
	pthread_mutex_t		write_mutex;
	t_fork				*forks;
	t_philo				*philos;
}						t_info;

int						error_exit(const char *error);
int						check_args(char **av);
void					valid_input(t_info *info, char **av);
void					*ft_memset(void *s, int i, size_t len);
void					*ft_calloc(size_t n_elements, size_t size);

void					data_init(t_info *infos);
void					handle_mutex(pthread_mutex_t *mutex, t_code code);
void					handle_thread(pthread_t *thread, void *(*foo)(void *),
							void *data, t_code code);
void					data_init(t_info *infos);

void					set_bool(pthread_mutex_t *mutex, t_bool *dest,
							t_bool value);
t_bool					get_bool(pthread_mutex_t *mutex, t_bool *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
t_bool					simulation_finished(t_info *infos);
void					wait_creation_philo(t_info *infos);
long					get_time(t_time_code time_code);
void					write_status(t_philo_status status, t_philo *philo);
void					precise_usleep(long usec, t_info *infos);
void					dinner_start(t_info *infos);
void					clean(t_info *infos);
void					increase_long(pthread_mutex_t *mutex, long *value);
t_bool					all_threads_running(pthread_mutex_t *mutex,
							long *threads, long philo_nbr);
void					*monitor_dinner(void *data);
void					synchronize_philo(t_philo *philo);
void					think(t_philo *philo, t_bool pre_simulation);
#endif
