/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:02:55 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/26 14:52:09 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	infos;

	if ((ac == 5 || ac == 6))
	{
		valid_input(&infos, av);
		data_init(&infos);
		dinner_start(&infos);
		clean(&infos);
	}
	else
	{
		error_exit("Wrong input!!\n"
			"How to use: ./philo 5 800 200 200 [5]");
	}
}
