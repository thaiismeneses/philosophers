/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:20:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/09 18:20:07 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_cutlery
{
//	int index;
	pthread_mutex_t fork;
//	int	status;
}	t_cutlery;

typedef struct s_philo
{
	int	id;
	time_t	tt_eat;
	time_t	tt_sleep;
	time_t	tt_die;
	int	nbr_meals_eaten;
	int	nbr_meals;
	t_cutlery	*left_fork;
	t_cutlery	*right_fork;
	time_t	last_meal;
}	t_philo;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	check_args(char **av);
void    ft_sleep(time_t ms);
void 	init_philosophers(t_philo *philosopher, t_cutlery *fork, char **av);
void	*actions(void *n);
time_t	get_time_in_ms(void);
#endif
