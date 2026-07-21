/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_life_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:52:08 by masad             #+#    #+#             */
/*   Updated: 2026/07/21 10:39:20 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_philos(t_table *table, int count)
{
	int	i;

	stop_simulation(table);
	i = 0;
	while (i < count)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

void	join_philos(t_table *table)
{
	int	i;
	int	num_philos;

	num_philos = table->num_philos;
	i = 0;
	while (i < num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

t_code	create_philos(t_table *table)
{
	int		i;
	int		num_philos;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	num_philos = table->num_philos;
	while (i < num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine,
				&philos[i]) != 0)
		{
			destroy_philos(table, i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
