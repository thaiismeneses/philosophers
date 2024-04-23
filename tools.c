/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:46:26 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:21 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_args(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0' && (ft_isdigit(av[i][j]) == 1))
			j++;
		if (av[i++][j] != '\0')
			return (0);
	}
	return (1);
}

long	get_time(void)
{
	long			time_ms;
	struct timeval	te;

	gettimeofday(&te, NULL);
	time_ms = (te.tv_sec * 1000);
	time_ms += (te.tv_usec / 1000);
	return (time_ms);
}

void	ft_sleep(long long ms)
{
	long	start_time;

	start_time = get_time();
	while (start_time + ms > get_time())
		usleep(100);
}

int	print_error(void)
{
	printf("Wrong input!\n");
	printf("How to use: ./philo nbr_of_philosophers time_to_die time_to_eat time_to_sleep\n ");
	return(1);
}

void	print_state(t_info *input, t_philo *philo, int status)
{
	pthread_mutex_lock(input->death_lock);
	if (input->death == false)
	{
		pthread_mutex_unlock(input->death_lock);
		pthread_mutex_lock(input->print_lock);
		printf("%ld     %d  %s", get_time() - input->start_time,
					philo->id_philo,
					input->status[status]);
		pthread_mutex_unlock(input->print_lock);
	}
	else
		pthread_mutex_unlock(input->death_lock);
}

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
	char *c;
	
	c = (char *)s;
	while (len > 0)
	{
		c[len - 1] = i;
		len--;
	}
	return (s);
}
