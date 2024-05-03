/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/05/03 17:56:44 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *dinner_simutation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_creation_philo(philo->infos);
    return (NULL);
}

void    dinner_start(t_info *infos)
{
    int i;

    i = 0;
    if (infos->nbr_limit_meals == 0)
        return ;
    else if (infos->philo_nbr == 1)
    //TODO
    else
    {
        while (i++ < infos->philo_nbr)
            handle_thread(&infos->philos[i],
                            dinner_simutation, &infos->philos[i], CREATE);
    }
   //get_time() 
    set_bool(&infos->info_mutex, &infos->all_philo_created, true);
}
