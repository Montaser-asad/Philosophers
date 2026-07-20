/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:40:52 by masad             #+#    #+#             */
/*   Updated: 2026/07/06 15:58:17 by masad            ###   ########.fr       */
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
	struct timeval	start;
	struct timeval	now;
	long			elapsed_us;

	gettimeofday(&start, NULL);
	while (is_simulation_running(table))
	{
		gettimeofday(&now, NULL);
		elapsed_us = (now.tv_sec - start.tv_sec) * 1000000
			+ (now.tv_usec - start.tv_usec);
		if (elapsed_us >= duration_ms * 1000)
			break;
		if ((duration_ms * 1000 - elapsed_us) > 10000)
			usleep(5000);
	}
}
