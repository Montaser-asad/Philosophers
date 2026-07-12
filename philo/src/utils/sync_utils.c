/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:07:56 by masad             #+#    #+#             */
/*   Updated: 2026/07/05 11:50:23 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_simulation_running(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->is_dining_lock);
	status = table->is_dining;
	pthread_mutex_unlock(&table->is_dining_lock);
	return (status);
}

void	stop_simulation(t_table *table)
{
	pthread_mutex_lock(&table->is_dining_lock);
	table->is_dining = 0;
	pthread_mutex_unlock(&table->is_dining_lock);
}

void	set_meals_info(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->meals_lock);
	philo->last_meal_time = time;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_lock);
}

int	get_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->meals_lock);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meals_lock);
	return (meals_eaten);
}

long	get_last_meal_time(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->meals_lock);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meals_lock);
	return (time);
}
