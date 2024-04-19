/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/09 18:12:34 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int main(int ac, char **av)
{
	t_philo	*philosophers;
	t_cutlery	*fork;
	pthread_t	*thread;
	int i;

	i = 0;
	if ((ac == 5 || ac == 6) && check_args(av))
	{
		philosophers = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
		thread = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
		fork = (t_cutlery *)malloc(sizeof(t_cutlery) * ft_atoi(av[1]));
		init_philosophers(philosophers, fork, av);

		while (i < ft_atoi(av[1]))
		{
			pthread_create(&thread[i], NULL, actions, &philosophers[i]);
			i++;
		}
		i = 0;
		while (i < ft_atoi(av[i]))
		{
			pthread_join(thread[i], NULL);
			i++;
		}
		i = 0;
		while (i < ft_atoi(av[i]))
		{
			printf("Philosopher %d ate %d meals\n", philosophers[i].id, philosophers[i].nbr_meals_eaten);
			i++;
		}
		i = 0;
		while (i < ft_atoi(av[i]))
		{
			pthread_mutex_destroy(&philosophers[i].left_fork->fork);
			i++;
		}
		//free(fork);
		//ree(thread);
		//free(philosophers);
	}
	else
		printf("How to use: ./thread nbr_of_philosophers time_to_die time_to_eat time_to	_sleep\n ");
	return (0);
}

