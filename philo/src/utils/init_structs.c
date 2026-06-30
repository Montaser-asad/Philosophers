/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:08:53 by masad             #+#    #+#             */
/*   Updated: 2026/06/30 20:53:33 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_code	init_philos(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->total);
	if (!table->philo)
		return (FAILURE);
	i = 0;
	while (i < table->total)
	{
		table->philo[i].id = i + 1;
		table->philo[i].meal_count = 0;
		table->philo[i].last_meal_time = 0;
		table->philo[i].table = table;
		i++;
	}
	return (SUCSSESS);
}

static t_code	init_table(t_table *table, int *args)
{
	table->total = args[TOTAL];
	table->time_to_die = args[TIME_TO_DIE];
	table->time_to_eat = args[TIME_TO_EAT];
	table->time_to_sleep = args[TIME_TO_SLEEP];
	table->meal_limit = args[MEAL_LIMIT];
	return (init_philos(table));
}

t_code	init_structs(int *args)
{
	t_table *table;
	t_code result;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		perror("Failed to allocate memory for table");
		exit(1);
	}
	if (!table || !args)
		return (FAILURE);
	result = init_table(table, args);
	return (result);
}
