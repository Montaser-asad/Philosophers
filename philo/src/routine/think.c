/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:59:20 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 19:03:19 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_code	philo_think(t_philo *philo)
{
	t_table *table;
	long time_to_think;

	table = philo->table;
	time_to_think = (table->time_to_die - table->time_to_eat
			- table->time_to_sleep) * 500;
	if (!(is_simulation_running(table)))
		return (FAILURE);
	if (time_to_think > 0)
		usleep(time_to_think );
	print_status(philo, "is thinking");
	// usleep(1000);

	return (SUCCESS);
}