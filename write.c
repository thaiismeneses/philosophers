/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:33:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/20 13:49:01 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(const char *error)
{
	printf("%s", error);
	return (0);
}

void	write_status(t_philo_status status, t_philo *philo)
{
	long	real_time;

	real_time = get_time(MILISECONDS) - philo->infos->start_routine;
	if (philo->full)
		return ;
	handle_mutex(&philo->infos->write_mutex, LOCK);
	if ((status == TAKEN_FIRST_FORK || status == TAKEN_SECOND_FORK)
		&& !simulation_finished(philo->infos))
		printf("%ld %d has taken a fork\n", real_time, philo->id);
	else if (status == EATING && !simulation_finished(philo->infos))
		printf("%ld %d is eating\n", real_time, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->infos))
		printf("%ld %d is sleeping\n", real_time, philo->id);
	else if (status == THINKING && !simulation_finished(philo->infos))
		printf("%ld %d is thinking\n", real_time, philo->id);
	else if (status == DIED)
		printf("%ld %d died\n", real_time, philo->id);
	handle_mutex(&philo->infos->write_mutex, UNLOCK);
}
