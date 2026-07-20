/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:33:02 by masad             #+#    #+#             */
/*   Updated: 2026/07/05 19:50:15 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_code	run_program(char **argv, int *args)
{
	if (parse_input(argv, args) == FAILURE)
		return (FAILURE);
	if (start_simulation(args) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int		*args;
	t_code	flag;

	if (argc != 6 && argc != 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(EXIT_FAILURE);
	}
	args = malloc(sizeof(int) * (5));
	if (!args)
		exit(EXIT_FAILURE);
	args[MEAL_LIMIT] = -1;
	flag = run_program(argv, args);
	free(args);
	if (flag == FAILURE)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
