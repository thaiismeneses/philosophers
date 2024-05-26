/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:15 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 14:53:40 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atol(const char *str)
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

static int	check_signal(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '+' || str[j] == '-')
		{
			if (str[j] == '-')
			{
				printf("Invalid!! Only positive numbers are allowed!!\n");
				return (0);
			}
			j++;
		}
		j++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] && check_signal(av[i]))
	{
		j = 0;
		while (av[i][j] != '\0' )
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Invalid!! Only digit caracters are allowed!!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_input(t_info *info, char **av)
{
	if (check_args(av))
	{
		info->philo_nbr = ft_atol(av[1]);
		if (info->philo_nbr > 200 || info->philo_nbr <= 0)
		{
			printf("Invalid number of philosophers!!\n");
			return (0);
		}
		info->tt_die = ft_atol(av[2]) * 1000;
		info->tt_eat = ft_atol(av[3]) * 1000;
		info->tt_sleep = ft_atol(av[4]) * 1000;
		if (info->tt_die < 60000 || info->tt_eat < 60000
			|| info->tt_sleep < 60000)
		{
			printf("The timestamp must be bigger than 60ms\n");
			return (0);
		}
		if (av[5])
			info->nbr_limit_meals = ft_atol(av[5]);
		else
			info->nbr_limit_meals = -1;
	}
	return (1);
}
