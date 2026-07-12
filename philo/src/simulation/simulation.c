/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:24:22 by masad             #+#    #+#             */
/*   Updated: 2026/07/07 12:49:14 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_code	start_simulation(int *args)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (FAILURE);
	if (init_structs(table, args) == FAILURE)
	{
		free_table(table);
		return (FAILURE);
	}
	table->start_time = get_time();
	if (create_philos(table) == FAILURE)
	{
		destroy_mutexes(table);
		free_table(table);
		return (FAILURE);
	}
	monitor(table);
	join_philos(table);
	destroy_mutexes(table);
	free_table(table);
	return (SUCSSESS);
}