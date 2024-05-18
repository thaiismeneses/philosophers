/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/18 12:29:54 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	write_status(THINKING, philo);
}

static void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKEN_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKEN_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILISECONDS));
	philo->meals_counter++;
	write_status(EATING, philo);
	precise_usleep(philo->infos->tt_eat, philo->infos);
	if (philo->infos->nbr_limit_meals > 0
		&& philo->meals_counter == philo->infos->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	handle_mutex(&philo->first_fork->fork, UNLOCK);
	handle_mutex(&philo->second_fork->fork, UNLOCK);
}

static void	*dinner_simutation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_creation_philo(philo->infos);
	while (!simulation_finished(philo->infos)) // set last meal
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->infos->tt_sleep, philo->infos);
		think(philo);
	}
	return (NULL);
}

void	dinner_start(t_info *infos)
{
	int	i;

	i = -1;
	if (infos->nbr_limit_meals == 0)
		return ;
	// else if (infos->philo_nbr == 1)
	// //TODO
	else
	{
		while (++i < infos->philo_nbr)
			handle_thread(&infos->philos[i].thread_id, dinner_simutation,
				&infos->philos[i], CREATE);
	}
	infos->start_routine = get_time(MILISECONDS);
	set_bool(&infos->info_mutex, &infos->all_philo_created, true);
	i = -1;
	while (++i < infos->philo_nbr)
		handle_thread(&infos->philos[i].thread_id, NULL, NULL, JOIN);
}
