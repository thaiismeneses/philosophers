/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:06:29 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/30 10:48:55 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(const char *error)
{
	printf("%s", error);
	return (1);
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

void	wait_creation_philo(t_info * infos)
{
	while (!get_bool(&infos->info_mutex, &infos->all_philo_created))
		;
}