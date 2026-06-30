/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:24:22 by masad             #+#    #+#             */
/*   Updated: 2026/06/30 23:47:59 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(int *args)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		perror("Failed to allocate memory for table");
		exit(1);
	}
	init_structs(table, args);
	for (int i = 0; i < table->total; i++)
		printf("Philo %d \n", table->philo[i].id);
}
