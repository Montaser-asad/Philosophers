/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:40:52 by masad             #+#    #+#             */
/*   Updated: 2026/07/20 18:24:47 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(long duration_ms, t_table *table)
{
	long	start_time;

	start_time = get_time();
	while (is_simulation_running(table))
	{
		if (get_time() - start_time >= duration_ms)
			break ;
		usleep(500);
	}
}
