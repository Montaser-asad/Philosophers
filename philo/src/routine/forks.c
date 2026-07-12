/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:52:46 by masad             #+#    #+#             */
/*   Updated: 2026/07/07 11:19:32 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	get_forks(t_philo *philo, pthread_mutex_t **left,
		pthread_mutex_t **right)
{
	int	philo_id;

	philo_id = philo->id;
	*left = &philo->table->forks[philo_id - 1];
	if (philo_id == philo->table->num_philos)
		*right = &philo->table->forks[0];
	else
		*right = &philo->table->forks[philo_id];
}

static t_code	lock_forks(t_table *table, pthread_mutex_t *first,
		pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	if (!is_simulation_running(table))
	{
		pthread_mutex_unlock(first);
		return (FAILURE);
	}
	pthread_mutex_lock(second);
	return (SUCSSESS);
}

t_code	take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;

	table = philo->table;
	get_forks(philo, &left_fork, &right_fork);
	if (philo->id % 2 == 1)
		return (lock_forks(table, right_fork, left_fork));
	return (lock_forks(table, left_fork, right_fork));
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	get_forks(philo, &left_fork, &right_fork);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
}
