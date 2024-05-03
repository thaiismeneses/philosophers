/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:17:29 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/03 11:01:22 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void handle_mutex_error(int status, t_code code)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == code || UNLOCK == code || DESTROY == code))
		error_exit("The value specified by mutex is invalid.");
	else if (EINVAL == status && INIT == code)
		error_exit("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (EBUSY == status)
		error_exit("Mutex is locked.");

}

void handle_mutex(pthread_mutex_t *mutex, t_code code)
{
	if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), code);
	else
		error_exit("Wrong code for mutex handle");
}
