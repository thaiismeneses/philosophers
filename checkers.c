/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:44:36 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/09 18:11:17 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//so_tem numeros 

//numeros maiores de 0 e mnor de 200 philosopher
#include "philos.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

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
	int i;
	//int nbr;

	i = 1;
	while (av)
	{
		printf("Arg[%d]: %s", i, av[i]);
		if (ft_isdigit(*av[i]) == 0)
			return (1);
		i++;
	}
	if (ft_atoi(av[0]) <= 0)
		return (1);
	return (0);
}
