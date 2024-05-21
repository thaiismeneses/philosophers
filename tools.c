/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:06:29 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/21 17:09:59 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	size_t	total;
	void	*allocated_memory;

	total = n_elements * size;
	allocated_memory = malloc(total);
	if (allocated_memory != NULL)
		ft_memset(allocated_memory, 0, total);
	return (allocated_memory);
}

void	*ft_memset(void *s, int i, size_t len)
{
	char	*c;

	c = (char *)s;
	while (len > 0)
	{
		c[len - 1] = i;
		len--;
	}
	return (s);
}

void	wait_creation_philo(t_info *infos)
{
	while (!get_bool(&infos->info_mutex, &infos->all_philo_created))
		;
}

/*long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failled");
	if (time_code == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time_code == MILISECONDS)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_code == MICROSECONDS)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("Wrong input to get_time!");
	return (1337);
}*/

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*void	precise_usleep(long usec, t_info *infos)
{
	long	start;
	long	used_time;
	long	remaining_time;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		if (simulation_finished(infos))
			break ;
		used_time = get_time(MICROSECONDS) - start;
		remaining_time = usec - used_time;
		if (remaining_time > 1e3)
			usleep(remaining_time / 2);
		else
			while (get_time(MICROSECONDS) - start < usec)
				;
	}
}*/

void	precise_usleep(long usec, t_info *infos)
{
	long	start;
	long	used_time;
	long	remaining_time;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < (usec / 1000))
	{
		if (simulation_finished(infos))
			break ;
		used_time = get_time_in_ms() - start;
		remaining_time = usec - (used_time * 1000);
		if (remaining_time > 1000)
			usleep(remaining_time / 2000);
		else
			while ((get_time_in_ms() - start) < (usec / 1000))
				;
	}
}

void	clean(t_info *infos)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < infos->philo_nbr)
	{
		philo = infos->philos + i;
		handle_mutex(&philo->philo_mutex, DESTROY);
	}
	handle_mutex(&infos->write_mutex, DESTROY);
	handle_mutex(&infos->info_mutex, DESTROY);
	free(infos->forks);
	free(infos->philos);
}

void	synchronize_philo(t_philo *philo)
{
	if (philo->infos->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->infos);
	}
	else
	{
		if (philo->id % 2 != 0)
			think(philo, true);
	}
}
