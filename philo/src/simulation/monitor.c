/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:56:42 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 19:10:49 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_code	check_meals_done(t_philo *philo)
{
	int		meal_limit;
	t_table	*table;

	table = philo->table;
	meal_limit = table->meal_limit;
	if (meal_limit == -1)
		return (FAILURE);
	if (get_meals_eaten(philo) < meal_limit)
		return (FAILURE);
	return (SUCCESS);
}

static t_code	all_ate_enough(t_table *table)
{
	int		i;
	int		num_philos;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	num_philos = table->num_philos;
	while (is_simulation_running(table) && i < num_philos)
	{
		if (check_meals_done(&philos[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static t_code	check_death(t_philo *philo)
{
	t_table	*table;
	long	current_time;
	long	last_meal_time;
	long	time_to_die;

	table = philo->table;
	time_to_die = table->time_to_die;
	last_meal_time = get_last_meal_time(philo);
	current_time = get_time();
	if ((current_time - last_meal_time) > time_to_die)
		return (SUCCESS);
	return (FAILURE);
}

void	monitor(t_table *table)
{
	int		i;
	t_philo	*philos;

	philos = table->philos;
	while (is_simulation_running(table))
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (check_death(&philos[i]) == SUCCESS)
			{
				print_status(&philos[i], "died");
				stop_simulation(table);
				return ;
			}
			i++;
		}
		if (all_ate_enough(table) == SUCCESS)
		{
			stop_simulation(table);
			return ;
		}
		usleep(500);
	}
}
