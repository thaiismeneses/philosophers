/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:14:17 by thfranco          #+#    #+#             */
/*   Updated: 2024/04/01 10:48:52 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//dinner_simutation TODO

void    dinner_start(t_info *infos)
{
    int i;

    i = -1
    if (infos->nbr_limit_meals == 0)
        return ;
    else if (infos->nbr_limit_meals == 1)
    //TODO
    else
    {
        while (i++ < infos->philo_nbr)
            handle_thread(&infos->philo[i], thread_id, dinner_simutation, &infos->philo[i], CREATE);
    }
}