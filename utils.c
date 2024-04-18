/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:40:07 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/13 19:40:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    ft_sleep(time_t ms)
{
    time_t  start_time;

    start_time = get_time_in_ms();
    while (start_time + ms > get_time_in_ms())
        usleep(100);
}


void	*actions(void *n)
{
	t_philo	*philosopher;
	int	meals_eaten;
	time_t	current_time;
	//int	thread = *(int *)n;
 
	philosopher = (t_philo *)n;
	meals_eaten = 0;
	current_time = get_time_in_ms();
	while (philosopher->nbr_meals == 0  || meals_eaten < philosopher->nbr_meals)
	{
		printf("\n Philosopher %d is thinking\n", philosopher->id);
		ft_sleep(philosopher->tt_sleep);

		pthread_mutex_lock(&philosopher->left_fork->fork);
		printf("\n Philosopher %d picked up left fork\n", philosopher->id);
		pthread_mutex_lock(&philosopher->right_fork->fork);
		printf("\n Philosopher %d picked up right fork\n", philosopher->id);

		printf("\n Philosopher %d is eating\n", philosopher->id);
        philosopher->last_meal = get_time_in_ms();
		usleep(philosopher->tt_eat);
		meals_eaten++;

		pthread_mutex_unlock(&philosopher->right_fork->fork);
		pthread_mutex_unlock(&philosopher->left_fork->fork);

		printf("\n Philosopher %d is sleeping\n", philosopher->id);
		ft_sleep(philosopher->tt_sleep);

		if (current_time - philosopher->last_meal > philosopher->tt_die)
		{
			printf("\n Philosopher %d died\n", philosopher->id);
		}
		philosopher->nbr_meals_eaten = meals_eaten;
	}
	return (NULL);
}

void 	init_philosophers(t_philo *philosopher, t_cutlery *fork, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&fork[i].fork, NULL);
		philosopher[i].id = i + 1;
		philosopher[i].nbr_meals_eaten = 0;
		philosopher[i].tt_die = ft_atoi(av[2]);
		philosopher[i].tt_eat = ft_atoi(av[3]);
		philosopher[i].tt_sleep = ft_atoi(av[4]);
		philosopher[i].nbr_meals = 0;
		philosopher[i].left_fork = &fork[i];
		philosopher[i].right_fork = &fork[(i + 1) % ft_atoi(av[1])];
		philosopher[i].last_meal = get_time_in_ms();
		i++;
	}
}
