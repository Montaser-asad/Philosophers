/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:59:21 by masad             #+#    #+#             */
/*   Updated: 2026/07/07 13:00:05 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_code	philo_sleep(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	if (!(is_simulation_running(table)))
		return (FAILURE);
	print_status(philo, "is sleeping");
	smart_sleep(table->time_to_sleep, table);
	return (SUCSSESS);
}