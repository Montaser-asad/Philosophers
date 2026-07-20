/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:08:53 by masad             #+#    #+#             */
/*   Updated: 2026/07/05 15:46:41 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_code	init_philos(t_table *table)
{
	int		i;
	int		num_philos;
	t_philo	*philos;

	num_philos = table->num_philos;
	table->philos = malloc(sizeof(t_philo) * num_philos);
	if (!table->philos)
		return (FAILURE);
	i = 0;
	philos = table->philos;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = get_time();
		philos[i].table = table;
		i++;
	}
	return (SUCCESS);
}

static t_code	init_table(t_table *table, int *args)
{
	table->num_philos = args[TOTAL];
	table->time_to_die = args[TIME_TO_DIE];
	table->time_to_eat = args[TIME_TO_EAT];
	table->time_to_sleep = args[TIME_TO_SLEEP];
	table->meal_limit = args[MEAL_LIMIT];
	table->is_dining = 1;
	table->start_time = 0;
	table->forks = NULL;
	if (init_philos(table) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

t_code	init_structs(t_table *table, int *args)
{
	if (init_table(table, args) == FAILURE)
		return (FAILURE);
	if (init_mutexes(table) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
