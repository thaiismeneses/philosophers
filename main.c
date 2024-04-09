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

pthread_t	philosopher[5];
pthread_mutex_t chopstick[5];



void	*actions(void *n)
{
	int	philo = *(int *)n;

	pthread_mutex_init(&chopstick[philo], NULL);
	//sleep(1);
	pthread_mutex_lock(&chopstick[philo]);
	pthread_mutex_lock(&chopstick[(philo + 1) % 5]);

	printf("\n Philosopher %d has taken a chopstick\n", philo);
	printf("\n Philosopher %d is eating\n", philo);
	sleep(1);
	pthread_mutex_unlock(&chopstick[philo]);
	pthread_mutex_unlock(&chopstick[(philo + 1) % 5]);

	printf("\n Philosopher %d is sleeping\n", philo);
	printf("\n Philosopher %d is thinking\n", philo);
	printf("\n Philosopher %d died\n", philo);


	return (NULL);
}

int main(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_args(av))
	{
		printf("Argumentos ok!!");
		/*int	i = 1;
		int	j = 1;
		
		while (i <= 5)
		{
			j = pthread_create(&philosopher[i], NULL, actions,(void *)&i);
			printf("\n Philosopher %d has been created\n", i);
			if (j != 0)
			{
				printf("\n Thread creation error\n");
				exit(1);
			}
			i++;
			sleep(1);
		}
		i = 1;
		while (i <= 5)
		{
			j = pthread_join(philosopher[i], NULL);
			if (j != 0)
			{
				printf("\n Thread join failed\n");
				exit(1);
			}
			i++;
		}
		i = 1;
		while (i <= 5)
		{
			j = pthread_mutex_destroy(&chopstick[i]);
			if (j != 0)
			{
				printf("\n Mutex destroyed\n");
				exit(1);
			}
			i++;
		}

		printf("After Thread\n");*/

	}
	else
		printf("How to use: ./philo nbr_of_philosophers time_to_die time_to_eat time_to	_sleep\n ");
	return (0);
}
