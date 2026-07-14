/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:35:05 by masad             #+#    #+#             */
/*   Updated: 2026/07/14 10:32:05 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                                                                            */
/*                                Includes                                    */
/*                                                                            */
/* ************************************************************************** */

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                                   ENUMS                                    */
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
/*                             		STRUCTS                                		*/
/*                                                                            */
/* ************************************************************************** */

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_limit;
	int					is_dining;
	long				start_time;
	pthread_mutex_t		is_dining_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_mutex_t		meals_lock;
	pthread_t			thread;
	t_table				*table;
}						t_philo;

/* ************************************************************************** */
/*                                                                            */
/*                               Prototype  				                    */
/*                                                                            */
/* ************************************************************************** */

/* ***************************** SIMULATION ******************************* */

t_code					init_structs(t_table *table, int *args);
t_code					init_mutexes(t_table *table);
void					destroy_mutexes(t_table *table);
void					destroy_forks(t_table *table, int idx);
void					destroy_meals_locks(t_table *table, int idx);
void					free_table(t_table *table);
t_code					start_simulation(int *args);
t_code					create_philos(t_table *table);
void					join_philos(t_table *table);
void					monitor(t_table *table);

/* ******************************** UTILS ********************************** */

t_code					parse_input(char *argv[], int *args);
int						is_simulation_running(t_table *table);
void					stop_simulation(t_table *table);
void					set_meals_info(t_philo *philo, long time);
int						get_meals_eaten(t_philo *philo);
long					get_last_meal_time(t_philo *philo);
long					get_time(void);
void					smart_sleep(long duration_ms, t_table *table);
void					print_status(t_philo *philo, char *status);

/* ******************************* ROUTINE ********************************* */

void					*philo_routine(void *arg);
t_code					philo_eat(t_philo *philo);
t_code					philo_sleep(t_philo *philo);
t_code					philo_think(t_philo *philo);
t_code					take_forks(t_philo *philo);
void					put_forks(t_philo *philo);
int						single_philo(t_philo *philo);
#endif