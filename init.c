/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:05:37 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 16:45:24 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(void)
{
	int	i;
	int	check;
	t_philo	**philos;
	t_info	input;

	input = set_input(NULL);
	philos = init_philos();
	input->forks = ft_calloc(input->nbr_philo, sizeof(pthread_mutex_t));
	i = 0;
	while (philos[i] != NULL)
	{
		check = pthread_mutex_init(&input->forks[i], NULL);
		if (check != 0)
		{
			printf("Error when initialising forks\n");
			return (1);
		}
		philos[i]->right_fork = i;
		i++;
	}
	philos[0]->left_fork = philo[--i]->right_fork;
	while (i > 0)
	{
		philos[i]=left_fork = philo[i - 1]->right_fork;
		i--;
	}
	return (0);
}

int	init_each_philo(int i)
{
	t_philo	**philos;

	philos = init_philos();
	philos[i] = ft_calloc(1, sizeof(t_philo));
	if (philos[i] == NULL)
	{
		free_philos();
		return (1);
	}
	philos[i]->nbr_philo = i + 1;
	philos[i]->eating = false;
	philos[i]->time_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	philos[i]->eat_lock = calloc(1, sizeof(pthread_mutex_t));
	philos[i]->running_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!philos[i]->time_lock || !philos[i]->eat_lock ||!philos[i]->running_lock)
	{
		free_philo();
		return (1);
	}
	pthread_mutex_init(philos[i]->running_lock, NULL);
	pthread_mutex_init(philos[i]->time_lock, NULL);
	pthread_mutex_init(philos[i]->eat_lock, NULL);
	return (0);
}

t_philo	**init_philos(t_bool init)
{
	t_philo	**philos;
	int				i;
	t_info			*input;

	if (init  == false)
		return(philos);
	input = set_input(NULL);
	philos = ft_calloc(input->nbr_philo + 1, sizeof(t_philo *));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < input->nbr_philo)
	{
		if (init_single_philo(i) == 1)
			return (NULL);
		i++;
	}
	if (init_forks() == 1)
	{
		free_philos();
		return (NULL);
	}
	return (philos);
}
