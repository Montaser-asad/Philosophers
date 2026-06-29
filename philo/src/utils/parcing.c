/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:57:36 by masad             #+#    #+#             */
/*   Updated: 2026/06/29 20:03:06 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int ft_isnumber(const char *str)
{
	int i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long ft_atoi (const char *str)
{
	int		sign;
    int 	i;
    long	result;

	i = 0;
	result = 0;
	tmp = result;
	sign = 1;
    while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-'|| str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
	    if (result > (LONG_MAX - (str[i] - '0')) / 10)
	        return (LONG_MAX);
	    result = result * 10 + (str[i] - '0');
	    i++;
	}
	return (result * sign);
}


void parse_input(char *argv[]) 
{   
	int 	i;
	long	n;

	i = 1;
    while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
		{
			printf("Error: Invalid input. Please provide valid numbers.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n == LONG_MAX)
		{
			printf("Error: Input value out of range. Please provide numbers within the range of int.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
