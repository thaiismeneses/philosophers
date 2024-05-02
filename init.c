/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/30 10:48:52 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//[philo_position + 1] % philo_nbr posição do garfo esquerdo
static void assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int philo_nbr;

	philo_nbr = philo->infos->philo_nbr;
	if (philo->id % 2 == 0) //if philo id is odd(impar)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % philo_nbr];
	}
	else
	{
		philo->first_fork = &forks[(position + 1) % philo_nbr];
		philo->second_fork = &forks[position];
	}
}

static void	philo_init(t_info *infos)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (i++ < infos->philo_nbr)
	{
		philo = infos->philos + 1;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->infos = infos;
		assign_forks(philo, infos->forks, i);
	}

}

void	data_init(t_info *infos)
{
	int	i;

	i = -1;
	infos->end_routine = false;
	infos->philos = calloc(infos->philo_nbr, sizeof(t_philo));
	infos->forks = calloc(infos->philo_nbr, sizeof(t_fork));
	while (i++ < infos->philo_nbr)
	{
		handle_mutex(&infos->forks[i].fork, INIT);
		infos->forks[i].fork_id = i;
	}
	philo_init(infos);
}
