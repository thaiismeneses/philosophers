/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:39:30 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 16:49:52 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_input(void)
{
	t_info	*input;

	input = set_input(NULL);
	pthread_mutex_destroy(input->death_lock);
	pthread_mutex_destroy(input->wait_lock);
	pthread_mutex_destroy(input->print_lock);
	free(input->death_lock);
	free(input->wait_lock);
	free(input->print_lock);
	free(input);

}


void	free_philos(void)
{
	t_philo	**philos;
	int		i;

	philos = init_philos(false);
	i = 0;
	while (philos[i] != NULL)
	{
		pthread_mutex_destroy(philos[i]->running_lock);
		pthread_mutex_destroy(philos[i]->eat_lock);
		pthread_mutex_destroy(philos[i]->time_lock);
		free(philos[i]->running_lock);
		free(philos[i]->eat_lock);
		free(philos[i]->time_lock);
		free(philos[i]);
		i++;
	}
	free(philos);
}