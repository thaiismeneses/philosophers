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
	int args_valid = check_args(av);
	if ((ac == 5 || ac == 6) && check_args(av))
	{
		printf("return of check args: %d\n", args_valid);
		printf("Argumentos ok!!");
	}
	else
	{
		printf("return of check args: %d\n", args_valid);
		printf("How to use: ./philo nbr_of_philosophers time_to_die time_to_eat time_to	_sleep\n ");
	}
	return (0);
}
