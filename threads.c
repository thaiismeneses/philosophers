/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:46:33 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 16:46:43 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	thread_join(void)
{
	int		i;
	int		check;
	t_philo	**philos;

	i = 0;
	check = 0;
	philos = set_philos(NULL);
	while (philos[i] != NULL && check == 0)
		check = pthread_join(philos[i++]->thread_id, NULL);
}


int	thread_creation(t_info *input, t_philo **philos)
{
	int 	i;
	int 	check;

	i = 0;
	check = 0;
	input->wait = true;
	while (i < input->nbr_philo && check  == 0)
	{
		check = thread_creat(&philos[i]->thread_id, NULL,
				&actions, philos[i]);
		usleep(100);
		i++;
	}
	if (check != 0)
		return (1);
	return (0);
}
