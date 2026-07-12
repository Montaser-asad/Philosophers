/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:56:18 by masad             #+#    #+#             */
/*   Updated: 2026/07/04 03:29:12 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_table *table, int idx)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	while (i < idx)
	{
		fork = &table->forks[i];
		pthread_mutex_destroy(fork);
		i++;
	}
}

void	destroy_meals_locks(t_table *table, int idx)
{
	int				i;
	pthread_mutex_t	*meal_lock;

	i = 0;
	while (i < idx)
	{
		meal_lock = &table->philos[i].meals_lock;
		pthread_mutex_destroy(meal_lock);
		i++;
	}
}

void	destroy_mutexes(t_table *table)
{
	if (!table)
		return ;
	if (table->forks)
	{
		destroy_forks(table, table->num_philos);
		free(table->forks);
		table->forks = NULL;
	}
	destroy_meals_locks(table, table->num_philos);
	pthread_mutex_destroy(&table->is_dining_lock);
	pthread_mutex_destroy(&table->print_lock);
}
