/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:49 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 14:59:24 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_thread(pthread_t *thread, void *(*foo)(void *), void *data,
		t_code code)
{
	if (code == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (code == JOIN)
		pthread_join(*thread, NULL);
	else if (code == DETACH)
		pthread_detach(*thread);
	else
		error_exit("Wrong code for thread handle");
}

t_bool	all_threads_running(pthread_mutex_t *mutex, long *threads,
		long philo_nbr)
{
	t_bool	ret;

	ret = false;
	handle_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	handle_mutex(mutex, UNLOCK);
	return (ret);
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	handle_mutex(mutex, LOCK);
	(*value)++;
	handle_mutex(mutex, UNLOCK);
}
