/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_and_setters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:23:06 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/03 12:23:09 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t * mutex, t_bool *dest, t_bool value)
{
	handle_mutex(mutex, LOCK);
	*dest = value;
	handle_mutex(mutex, UNLOCK);
}

t_bool	get_bool(pthread_mutex_t *mutex, t_bool *value)
{
	t_bool	new;

	handle_mutex(mutex, LOCK);
	new = *value;
	handle_mutex(mutex, UNLOCK);
	return (new);
}

void	set_long(pthread_mutex_t * mutex, long *dest, long value)
{
	handle_mutex(mutex, LOCK);
	*dest = value;
	handle_mutex(mutex, UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	new;

	handle_mutex(mutex, LOCK);
	new = *value;
	handle_mutex(mutex, UNLOCK);
	return (new);
}

t_bool	simulation_finished(t_info *infos)
{
	return (get_bool(&infos->info_mutex, &infos->end_routine));
}