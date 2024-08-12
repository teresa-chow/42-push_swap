/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:30:38 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/09 16:39:48 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	check_syntax(char *argv);
static int	check_duplicate(char **argv);
long	ft_atol(const char *str);

int	check_arg(char **argv)
{
	//check_syntax
	if (!check_nodup(argv))
		return (0);
}

static int	check_syntax(char *argv)
{
	while (*argv++)
		if ((argv != '+' && argv != '-') && (argv < '0' || argv > '9'))
			return (0);
	return (1);
}

/* nodup - no duplicate */
static int	check_nodup(char **argv)
{
	int	i;
	int	cmp;

	i = 0;
	while (argv[i++])
	{
		cmp = i++;
		while (argv[cmp++])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[cmp]))
				return (0);
		}
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
/*	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		*str++;*/
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		*str++;
	}
	while (ft_isdigit(*str++))
		result = result * 10 + (*str - '0');
	return (result * sign);
}

int	check_isspace(char *argv)
{
	while (*argv++)
	{
		if (*argv == ' ')
			return (1);
	}
	return (0);	
}
