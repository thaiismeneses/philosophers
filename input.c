/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:07:15 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 16:49:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_input(void)
{
	t_info	*input;
	
	input = get_input();
	input->status[is_eating] = "is eating\n";
	input->status[grabbed_fork] = "has taken a fork\n";
	input->status[is_sleeping] = "is sleeping\n";
	input->status[is_thinking] = "is thinking\n";
	input->status[is_dead] = "died\n";
	input->status[6] = NULL;
	input->print_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	input->death_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	input->wait_lock = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!input->death_lock || !input->wait_lock || !input->print_lock)
	{
		free_input();
		return (1);
	}
	return (0);
}


t_info	*set_input(char **av)
{
	static t_info	*input;

	if (av == NULL)
		return (input);
	input = calloc(1, sizeof(t_info));
	if (!input)
		return (NULL);
	if (init_input() == 1)
		return (NULL);
	pthread_mutex_init(input->print_lock, NULL);
	pthread_mutex_init(input->death_lock, NULL);
	pthread_mutex_init(input->wait_lock, NULL);
	return (input);
}

t_info	*get_input(void)
{
	return (set_input(NULL));
}

