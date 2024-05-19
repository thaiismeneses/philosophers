/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:49 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/19 18:31:49 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void handle_thread_error(int status, t_code code)
{
	if (0 == status)
		return ;
	if (EAGAIN== status)
		error_exit("No resources to create another thread.");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission.\n");
	else if (EINVAL == status && CREATE == code)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == code || DETACH == code))
		error_exit("The value specified by thread is not joinable\n.");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that."
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of."
			"thread specifies the calling thread.");
}*/
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
