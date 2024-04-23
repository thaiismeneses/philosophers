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

#inlcude "philo.h"

void	free_input(void)
{
	t_input	*input;

	input = set_input(NULL);
	pthread_mutex_destroy(input->death_lock);
	pthread_mutex_destroy(input->wait_lock);
	pthread_mutex_destroy(input->print_lock);
	free(input->death_lock);
	free(input->wait_lock);
	free(input->print_lock);
	free(input);

}
