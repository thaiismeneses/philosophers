/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:55:35 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:06 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	*input;
	t_philo	**philos;

	input = NULL;
	if ((ac < 5 || ac > 6) || !check_args(av))
		return(print_error());
	input = set_input(av);
	if (input  == NULL)
		return (1);
	else
	{
		philos = init_philos(true);
		if (philos == NULL || philos[0] == NULL)
		{
			printf("Error while creating philosophers\n");
			return (1);
		}
		if (thread_creation(input, philos) == 1)
			return (1);
	}
	//watcher();
	return (0);
}

