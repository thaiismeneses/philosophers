/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:15 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/03 11:01:05 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_isdigit(int c)
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

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (av[i][j] == '+' || av[i][j] == '-')
	{
		if (av[i][j] == '-')
			error_exit("Invalid!! Only positive numbers are allowed!!");
		j++;
	}
	while(av[i])
	{
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
				error_exit("Invalid!! Only digit caracters are allowed!!");
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_input(t_info *info, char **av)
{
	
	if (check_args(av) == 0)
	{

		info->philo_nbr = ft_atol(av[1]);
		info->tt_die = ft_atol(av[2]) * 1000;
		info->tt_eat = ft_atol(av[3]) * 1000;
		info->tt_sleep = ft_atol(av[4]) * 1000;
		if (info->tt_die < 60000 
			|| info->tt_eat < 6000 || info->tt_sleep < 6000)
			error_exit("The timestamp must be bigger than 60ms");
		if (av[5])
			info->nbr_limit_meals = ft_atol(av[5]); 
		else
			info->nbr_limit_meals = -1;
	}
}

