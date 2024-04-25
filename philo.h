/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:20:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 17:00:27 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648


//boolean
typedef enum e_bool
{
	false,
	true,
}					t_bool;

//info about the input
typedef struct s_info
{
	long long		nbr_philo;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	long long		nbr_must_eat[2];
	long			start_time;
	t_bool				death;
	t_bool				wait;
	char 			*status[7];
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*wait_lock;
	pthread_mutex_t	*print_lock;	
	pthread_mutex_t	*forks;
}					t_info;

//info about each philosopher 
typedef struct s_philo
{
	int					id_philo;
	t_bool				running;
	t_bool				eating;
	int					right_fork;
	int					left_fork;
	pthread_mutex_t	*running_lock;
	pthread_mutex_t	*eat_lock;
	pthread_t	thread_id;
	pthread_mutex_t	*time_lock;
	long				time_philo;

}					t_philo;

//status
typedef	enum e_status
{
	is_eating,
	grabbed_fork,
	is_sleeping,
	is_thinking,
	is_dead,
}					t_status;


long long	ft_atol(const char *str);
long	get_time(void);
int	print_error(void);
int	ft_isdigit(int c);
int	check_args(char **av);
void	ft_sleep(long long ms);
int	print_error(void);
void	print_state(t_info *input, t_philo *philo, int status);
void	*ft_memset(void *s, int i, size_t len);
void	*ft_calloc(size_t n_elements, size_t size);

void	ft_input(void);
t_info	*set_input(char **av);

int	init_input(void);
//int	init_forks(void);
//int	init_each_philo(int i);
t_philo	**init_philos(t_bool init);
t_info	*get_input(void);


void	tread_join(void);
int	thread_creation(t_info *input, t_philo **philos);

void	philo_beginning(t_info *input, t_philo *philo);
void	philo_eat_sleep_think(t_info *input, t_philo *philo);
t_bool	philo_sequence_actions(t_info *input, t_philo *philo);
void	philo_actions(t_info *input, t_philo *philo);
void	*routine(void	*arg);

void	free_input(void);
void	free_philos(void);


#endif
