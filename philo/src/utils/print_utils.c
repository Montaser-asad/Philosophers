/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:58:30 by masad             #+#    #+#             */
/*   Updated: 2026/07/07 12:58:46 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *status)
{
	t_table *table;
	long timestamp;

	table = philo->table;
	pthread_mutex_lock(&table->print_lock);
	if (is_simulation_running(table))
	{
		timestamp = get_time() - table->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&table->print_lock);
}