/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:33:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/17 21:56:15 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(const char *error)
{
	printf("%s", error);
	return (1);
}

void	write_status(t_philo_status status, t_philo *philo)
{
	long	real_time;

	real_time = get_time(MILISECONDS) - philo->infos->start_routine;
	if (philo->full)
		return ;
	handle_mutex(&philo->infos->write_mutex, LOCK);
	if ((status == TAKEN_FIRST_FORK || status == TAKEN_SECOND_FORK)
		&& !simulation_finished(philo->infos))
		printf("%ld %d has taken a fork\n", real_time, philo->id);
	else if (status == EATING && !simulation_finished(philo->infos))
		printf("%ld %d is eating\n", real_time, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->infos))
		printf("%ld %d is sleeping\n", real_time, philo->id);
	else if (status == THINKING && !simulation_finished(philo->infos))
		printf("%ld %d is thinking\n", real_time, philo->id);
	else if (status == DIED  && !simulation_finished(philo->infos))
		printf("%ld %d died\n", real_time, philo->id);
	handle_mutex(&philo->infos->write_mutex, UNLOCK);

}


void print_philo(t_philo *philo) {
    if (philo == NULL) {
        printf("Philo is NULL\n");
        return;
    }
    printf("Philo ID: %d\n", philo->id);
    printf("Meals Counter: %ld\n", philo->meals_counter);
    printf("Full: %d\n", philo->full);
    printf("Last Meal Time: %ld\n", philo->last_meal_time);
    printf("First Fork: %p\n", (void*)philo->first_fork);
    printf("Second Fork: %p\n", (void*)philo->second_fork);
    printf("Thread ID: %lu\n", (unsigned long)philo->thread_id);
    printf("Philo Mutex: %p\n", (void*)&philo->philo_mutex);
    printf("Infos: %p\n", (void*)philo->infos);
}

void print_info(t_info *info) {
    if (info == NULL) {
        printf("Info is NULL\n");
        return;
    }
    printf("Philo Number: %ld\n", info->philo_nbr);
    printf("Time to Die: %ld\n", info->tt_die);
    printf("Time to Eat: %ld\n", info->tt_eat);
    printf("Time to Sleep: %ld\n", info->tt_sleep);
    printf("Number Limit Meals: %ld\n", info->nbr_limit_meals);
    printf("Start Routine: %ld\n", info->start_routine);
    printf("All Philo Created: %d\n", info->all_philo_created);
    printf("End Routine: %d\n", info->end_routine);
    printf("Info Mutex: %p\n", (void*)&info->info_mutex);
    printf("Write Mutex: %p\n", (void*)&info->write_mutex);
    printf("Forks: %p\n", (void*)info->forks);
    printf("Philos: %p\n", (void*)info->philos);
}
