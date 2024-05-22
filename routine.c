/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/22 13:51:14 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo, t_bool pre_simulation)
{
	long	tt_eat;
	long	tt_sleep;
	long	tt_think;

	if (!pre_simulation)
		write_status(THINKING, philo);
	if (philo->infos->philo_nbr % 2 == 0)
		return ;
	tt_eat = philo->infos->tt_eat;
	tt_sleep = philo->infos->tt_sleep;
	tt_think = (tt_eat * 2) - tt_sleep;
	if (tt_think < 0)
		tt_think = 0;
	precise_usleep(tt_think * 0.42, philo->infos);
}
static void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_creation_philo(philo->infos);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time_in_ms());
	increase_long(&philo->infos->info_mutex, &philo->infos->threads_running_n);
	write_status(TAKEN_FIRST_FORK, philo);
	while (!simulation_finished(philo->infos))
		usleep(200);
	return (NULL);
}
static void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKEN_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKEN_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time_in_ms());
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
	//wait_creation_philo(philo->infos);
	usleep(200);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time_in_ms());
	increase_long(&philo->infos->info_mutex, &philo->infos->threads_running_n);
	synchronize_philo(philo);
	while (!simulation_finished(philo->infos)) // set last meal
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->infos->tt_sleep, philo->infos);
		think(philo, false);
	}
	return (NULL);
}

void	dinner_start(t_info *infos)
{
	int	i;

	i = -1;
	if (infos->nbr_limit_meals == 0)
		return ;
	else if (infos->philo_nbr == 1)
		handle_thread(&infos->philos[0].thread_id, one_philo, &infos->philos[0],
			CREATE);
	else
	{
		while (++i < infos->philo_nbr)
			handle_thread(&infos->philos[i].thread_id, dinner_simutation,
				&infos->philos[i], CREATE);
	}
	handle_thread(&infos->monitor, monitor_dinner, infos, CREATE);
	set_long(&infos->info_mutex, &infos->start_routine, get_time_in_ms());
	//infos->start_routine = get_time_in_ms();
	set_bool(&infos->info_mutex, &infos->all_philo_created, true);
	i = -1;
	while (++i < infos->philo_nbr)
		handle_thread(&infos->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&infos->info_mutex, &infos->end_routine, true);
	handle_thread(&infos->monitor, NULL, NULL, JOIN);
}
