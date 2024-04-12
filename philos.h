/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:20:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/09 18:20:07 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct cutlery
{
	int index;
	int	status;
}	cutlery;

typedef struct philo
{
	int	index;
	pthread_t	philosopher;
	time_t	tt_eat;
	time_t	tt_sleep;
	time_t	tt_die;
}	philo;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	check_args(char **av);

#endif
