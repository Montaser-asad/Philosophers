/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:59:15 by masad             #+#    #+#             */
/*   Updated: 2026/07/21 10:38:44 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (single_philo(philo))
		return (NULL);
	while (is_simulation_running(table))
	{
		if (philo_eat(philo) == FAILURE)
			break ;
		if (philo_sleep(philo) == FAILURE)
			break ;
		if (philo_think(philo) == FAILURE)
			break ;
	}
	return (NULL);
}
