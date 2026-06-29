/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:57:36 by masad             #+#    #+#             */
/*   Updated: 2026/06/28 19:57:57 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int check_overflow ();

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if(!ft_isdigit((int *) str[i]))
			return 0;
		i++;
	}
	return 1;
}

static long atoi (char *str)
{
	int	sign;
    int i;
    int	result;
	int	tmp;

	i = 0;
	result = 0;
	tmp = result;
	sign = 1;
    while (str[i] ==' ' || str[i] == '	' )
		i++;
	if (str[i] == '-'|| str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isnumber(str[i]))
			return 1;
		if (tmp != result)
			return LONG_MAX;
		result = (result * 10) + str[i] - '0';
		tmp = result;	
	}

}


void parse_input(char *argv[]) 
{   

    while ();
}
