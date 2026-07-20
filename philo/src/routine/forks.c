/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:52:46 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 10:41:03 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	get_forks(t_philo *philo, pthread_mutex_t **left,
		pthread_mutex_t **right)
{
	int				philo_id;
	pthread_mutex_t	*forks;

	philo_id = philo->id;
	forks = philo->table->forks;
	*left = &forks[philo_id - 1];
	if (philo_id == philo->table->num_philos)
		*right = &forks[0];
	else
		*right = &forks[philo_id];
}

static t_code	lock_forks(t_table *table, pthread_mutex_t *first,
		pthread_mutex_t *second, t_philo *philo)
{
	pthread_mutex_lock(first);
	if (!is_simulation_running(table))
	{
		pthread_mutex_unlock(first);
		return (FAILURE);
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second);
	if (!is_simulation_running(table))
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (FAILURE);
	}
	print_status(philo, "has taken a fork");
	return (SUCCESS);
}

t_code	take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;

	table = philo->table;
	get_forks(philo, &left_fork, &right_fork);
	if (philo->id % 2 == 1)
		return (lock_forks(table, right_fork, left_fork, philo));
	return (lock_forks(table, left_fork, right_fork, philo));
}

// 5%2 = 1

int	single_philo(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	t_table			*table;

	table = philo->table;
	right_fork = &table->forks[philo->id - 1];
	if (table->num_philos == 1)
	{
		pthread_mutex_lock(right_fork);
		print_status(philo, "has taken a fork");
		set_meals_info(philo, get_time());
		smart_sleep(table->time_to_die, table);
		pthread_mutex_unlock(right_fork);
		return (1);
	}
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	get_forks(philo, &left_fork, &right_fork);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
}
