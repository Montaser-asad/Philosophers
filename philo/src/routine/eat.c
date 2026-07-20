/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:59:11 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 10:18:15 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_code	philo_eat(t_philo *philo)
{
	t_table	*table;
	long	time_to_eat;

	table = philo->table;
	time_to_eat = table->time_to_eat;
	if (!(is_simulation_running(table)))
		return (FAILURE);
	if (take_forks(philo) == FAILURE)
		return (FAILURE);
	set_meals_info(philo, get_time());
	print_status(philo, "is eating");
	smart_sleep(time_to_eat, table);
	put_forks(philo);
	return (SUCCESS);
}
