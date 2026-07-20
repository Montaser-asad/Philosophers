/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:59:20 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 10:21:50 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_code	philo_think(t_philo *philo)
{
	t_table *table;
	long time_to_think;

	time_to_think = 0;
	table = philo->table;
	if (!(is_simulation_running(table)))
		return (FAILURE);
	print_status(philo, "is thinking");
	return (SUCCESS);
}