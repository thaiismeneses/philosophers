/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:16:27 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/30 10:49:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define EINVAL 1
# define EDEADLK 2
# define EPERM 3
# define ENOMEM 4
# define EBUSY 5
# define EAGAIN 6
#define ESRCH 7

typedef struct s_info t_info;

typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	CREATE,
	JOIN,
	DETACH,
	DESTROY,
}	t_code;

//boolean
typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef	struct s_fork
{
	pthread_mutex_t	fork;
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	int	id;
	long	meals_counter;
	t_bool	full;
	long	last_meal_time;
	t_fork	*first_fork;
	t_fork	*second_fork;
	pthread_t	thread_id; // a philo ia a thread
	t_info	*infos;
	//	nbr_meals;
}    t_philo;

typedef struct s_info
{
	long	philo_nbr;
	long	tt_die;
	long	tt_eat;
	long	tt_sleep;
	long	nbr_limit_meals; // if does not have the nbr of meals will be -1
	long	start_routine;
	t_bool	end_routine; // if a philo dies or all of them have eaten
	t_fork	*forks;
	t_philo	*philos;
}	t_info;

int	error_exit(const char *error);
int	check_args(char **av);
void	valid_input(t_info *info, char **av);
void	*ft_memset(void *s, int i, size_t len);
void	*ft_calloc(size_t n_elements, size_t size);

void	data_init(t_info *infos);
void handle_mutex(pthread_mutex_t *mutex, t_code code);
void handle_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_code code);
void	data_init(t_info *infos);
#endif
