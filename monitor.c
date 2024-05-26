/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:39:48 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 15:33:15 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_died(t_philo *philo)
{
	long	used_time;
	long	tt_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	used_time = get_time_in_ms() - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	tt_die = philo->infos->tt_die / 1e3;
	if (used_time > tt_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	t_info	*infos;
	int		i;

	infos = (t_info *)data;
	while (!all_threads_running(&infos->info_mutex, &infos->threads_running_n,
			infos->philo_nbr))
		;
	while (!simulation_finished(infos))
	{
		i = -1;
		while (++i < infos->philo_nbr && !simulation_finished(infos))
		{
			if (philo_died(infos->philos + i))
			{
				set_bool(&infos->info_mutex, &infos->end_routine, true);
				write_status(DIED, infos->philos + i);
			}
		}
	}
	return (NULL);
}

void	synchronize_philo(t_philo *philo)
{
	if (philo->infos->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->infos);
	}
	else
	{
		if (philo->id % 2 != 0)
			think(philo, true);
	}
}
