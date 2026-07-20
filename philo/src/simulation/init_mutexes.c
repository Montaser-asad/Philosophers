/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:59:00 by masad             #+#    #+#             */
/*   Updated: 2026/07/07 11:49:44 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// destroy the rest of mutexes

static t_code	init_forks(t_table *table)
{
	int				i;
	int				philo_num;
	pthread_mutex_t	*fork;

	i = 0;
	philo_num = table->num_philos;
	table->forks = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!table->forks)
		return (FAILURE);
	while (i < philo_num)
	{
		fork = &table->forks[i];
		if (pthread_mutex_init(fork, NULL))
		{
			destroy_forks(table, i);
			free(table->forks);
			table->forks = NULL;
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static t_code	init_meals_locks(t_table *table)
{
	int				i;
	int				philo_num;
	pthread_mutex_t	*meal_lock;

	i = 0;
	philo_num = table->num_philos;
	while (i < philo_num)
	{
		meal_lock = &table->philos[i].meals_lock;
		if (pthread_mutex_init(meal_lock, NULL))
		{
			destroy_meals_locks(table, i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static t_code	init_dining_lock(t_table *table)
{
	pthread_mutex_t	*is_dining_lock;

	is_dining_lock = &(table->is_dining_lock);
	if (pthread_mutex_init(is_dining_lock, NULL))
		return (FAILURE);
	return (SUCCESS);
}

static t_code	init_print_lock(t_table *table)
{
	pthread_mutex_t	*print_lock;

	print_lock = &(table->print_lock);
	if (pthread_mutex_init(print_lock, NULL))
		return (FAILURE);
	return (SUCCESS);
}

t_code	init_mutexes(t_table *table)
{
	if (init_dining_lock(table) == FAILURE)
		return (FAILURE);
	if (init_print_lock(table) == FAILURE)
	{
		pthread_mutex_destroy(&table->is_dining_lock);
		return (FAILURE);
	}
	if (init_meals_locks(table) == FAILURE)
	{
		pthread_mutex_destroy(&table->is_dining_lock);
		pthread_mutex_destroy(&table->print_lock);
		return (FAILURE);
	}
	if (init_forks(table) == FAILURE)
	{
		pthread_mutex_destroy(&table->is_dining_lock);
		pthread_mutex_destroy(&table->print_lock);
		destroy_meals_locks(table, table->num_philos);
		return (FAILURE);
	}
	return (SUCCESS);
}
