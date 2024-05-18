/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:49 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/18 12:30:50 by thfranco         ###   ########.fr       */
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

void handle_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_code code)
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
