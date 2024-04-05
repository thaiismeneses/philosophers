/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/05 14:52:54 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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

int main(void)
{
	int	i = 1;
	int	j = 1;
	
	printf("Before Thread\n");
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

	printf("After Thread\n");
	return (0);
}
