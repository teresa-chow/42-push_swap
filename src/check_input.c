/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:29:20 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/02 14:21:09 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//static int	check_syntax(char *argv);
//static int	check_nodup(char **argv);
//long	ft_atol(const char *str);

int	check_input(int argc, char **argv)
{
	if (argc == 2 && check_space(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (write(2, "Error\n", 6));
	}

	//check_syntax
	//check_limits
	if (!check_nodup(argv))
		return (0);
}

/*static int	check_syntax(char *arg)
{
	int	i;

	i = 0;
	while (arg[i++])
	{
		if (arg[0] != '+' && arg[0] != '-') && (!ft_isdigit(arg[0]))
			return (0);
		else if (arg[0] == '+' || arg[0] == '-') && (!ft_isdigit(arg[1]))
			return (0);
		else if (!ft_isdigit(&arg[i]))
			return (0);
	}
	return (1);
}*/

/* nodup - no duplicate */
/*static int	check_nodup(char **arg)
{
	int	i;
	int	cmp;

	i = 0;
	while (arg[i++])
	{
		cmp = i++;
		while (arg[cmp++])
		{
			if (ft_atol(arg[i]) == ft_atol(arg[cmp]))
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
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		*str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		*str++;
	}
	while (ft_isdigit(*str++))
		result = result * 10 + (*str - '0');
	return (result * sign);
}*/

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);	
}
