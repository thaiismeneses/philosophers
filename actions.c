/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:58:38 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 17:00:17 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_beginning(t_info *input, t_philo *philo)
{
	pthread_mutex_lock(philo->running_lock);
	philo->running = true;
	pthread_mutex_unlock(philo->running_lock);
	pthread_mutex_lock(input->wait_lock);
	while (input->wait == true)
	{
		pthread_mutex_unlock(input->wait_lock);
		usleep(1);
		pthread_mutex_lock(input->wait_lock);
	}
	pthread_mutex_lock(philo->time_lock);
	philo->time_philo = get_time();
	pthread_mutex_unlock(philo->time_lock);
	pthread_mutex_unlock(input->wait_lock);
	if (philo->id_philo % 2 == 0)
		ft_sleep(input->tt_eat / 2);
}

void	philo_eat_sleep_think(t_info *input, t_philo *philo)
{
	pthread_mutex_unlock(input->death_lock);
	print_state(input, philo, is_eating);
	pthread_mutex_lock(philo->eat_lock);
	philo->eating = true;
	pthread_mutex_unlock(philo->eat_lock);
	pthread_mutex_lock(philo->time_lock);
	philo->time_philo = get_time();
	pthread_mutex_unlock(philo->time_lock);
	ft_sleep(input->tt_eat);
	pthread_mutex_unlock(&input->forks[philo->left_fork]);
	pthread_mutex_unlock(&input->forks[philo->right_fork]);
	pthread_mutex_lock(philo->eat_lock);
	philo->eating = false;
	pthread_mutex_unlock(philo->eat_lock);
	print_state(input, philo, is_sleeping);
	ft_sleep(input->tt_sleep);
	print_state(input, philo, is_thinking);
}

t_bool	philo_sequence_actions(t_info *input, t_philo *philo)
{
	pthread_mutex_lock(&input->forks[philo->left_fork]);
	print_state(input, philo, grabbed_fork);
	pthread_mutex_lock(input->death_lock);
	if (input->death == false)
	{
		philo_eat_sleep_think(input, philo);
		return (0);
	}
	pthread_mutex_unlock(input->death_lock);
	pthread_mutex_unlock(&input->forks[philo->left_fork]);
	pthread_mutex_unlock(&input->forks[philo->right_fork]);
	return (1);
}


void	philo_actions(t_info *input, t_philo *philo)
{
	int	eat;

	eat = 0;
	while ((input->nbr_must_eat[0] == true && eat < input->nbr_must_eat[1]
			&& eat < INT_MAX)
			|| (input->nbr_must_eat[0] == false && eat < INT_MAX))
	{
		pthread_mutex_lock(&input->forks[philo->right_fork]);
		print_state(input, philo, grabbed_fork);
		if (input->nbr_philo = 1)
		{
			pthread_mutex_unlock(&input->forks[philo->right_fork]);
			ft_sleep(input->tt_die + 1);
			break;
		}
		if (philo_sequence_actions(input, philo) == 1)
			break;
		else
			eat++;
	}
}


void	*routine(void	*arg)
{
	t_info	input;
	t_philo	*philo;

	if (arg != NULL)
	{
		input = set_input(NULL);
		philo = (t_philo *)arg;
		philo_beginning(&input, philo);
		philo_actions(&input, philo);
		pthread_mutex_lock(philo->running_lock);
		philo->running = false;
		pthread_mutex_unlock(philo->running_lock);
	}
	return (NULL);
}
