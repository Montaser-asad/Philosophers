/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:35:05 by masad             #+#    #+#             */
/*   Updated: 2026/06/30 20:48:13 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                                                                            */
/*                                   Includes                                 */
/*                                                                            */
/* ************************************************************************** */

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                                     ENUMS                                  */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_code
{
	SUCSSESS,
	FAILURE
}						t_code;

typedef enum e_info
{
	TOTAL,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MEAL_LIMIT
}						t_info;

/* ************************************************************************** */
/*                                                                            */
/*                                     STRUCTS                                */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_table
{
	int					total;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_limit;
	t_philo				*philo;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meal_count;
	long long			last_meal_time;
	t_table				*table;
}						t_philo;

void					parse_input(char *argv[], int *n);
t_code					init_structs(int *args);
void					free_table(t_table *table);
#endif