/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:02:55 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/29 15:56:44 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_info	infos;

	if (ac == 5 || ac == 6)
	{
		//errors checkig, filling table
		valid_input(&infos, av);
		//creating the actual thing
		data_init(&infos);
		//start dinner

		//finish with no leakage when philo finished eat | philo dies 
		
	}
	else
	{
		error_exit("Wrong input!!\n"
			"How to use: ./philo 5 800 200 200 [5]");
	}
}
