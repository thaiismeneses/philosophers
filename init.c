/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 14:54:44 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->infos->philo_nbr;
	if (philo->id % 2 == 0)
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
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < infos->philo_nbr)
	{
		philo = infos->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->infos = infos;
		handle_mutex(&philo->philo_mutex, INIT);
		assign_forks(philo, infos->forks, i);
	}
}

void	data_init(t_info *infos)
{
	int	i;

	i = -1;
	infos->end_routine = false;
	infos->all_philo_created = false;
	infos->threads_running_n = 0;
	infos->start_routine = 0;
	infos->philos = ft_calloc(infos->philo_nbr, sizeof(t_philo));
	infos->forks = ft_calloc(infos->philo_nbr, sizeof(t_fork));
	handle_mutex(&infos->write_mutex, INIT);
	handle_mutex(&infos->info_mutex, INIT);
	while (++i < infos->philo_nbr)
	{
		handle_mutex(&infos->forks[i].fork, INIT);
		infos->forks[i].fork_id = i;
	}
	philo_init(infos);
}
