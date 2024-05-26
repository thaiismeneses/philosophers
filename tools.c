/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:06:29 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 15:32:48 by thfranco         ###   ########.fr       */
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

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

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
