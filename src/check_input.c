/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:29:20 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:48:10 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**check_argc2(char **argv);
static int	check_syntax(char *arg);
static int	check_limits(char *arg);

char	**check_input(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		argv = check_argc2(argv);
		i = 0;
	}
	check_nodup(argc, argv);
	i = 1;
	while (argv[i])
	{
		if (!check_syntax(argv[i]) || !check_limits(argv[i]))
		{
			if (argc == 2)
				free_strarray(argv);
			printerr_exit();
		}
		i++;
	}
	return (argv);
}

static char	**check_argc2(char **argv)
{
	if (!check_space(argv[1]))
	{
		if (!check_syntax(argv[1]) || !check_limits(argv[1]))
			printerr_exit();
		exit (EXIT_SUCCESS);
	}
	if (check_space(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			printerr_exit();
	}
	return (argv);
}

static int	check_syntax(char *arg)
{
	int	i;

	if ((arg[0] != '+' && arg[0] != '-') && (!ft_isdigit(arg[0])))
		return (0);
	if ((arg[0] == '+' || arg[0] == '-') && (!ft_isdigit(arg[1])))
		return (0);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_limits(char *arg)
{
	long	input;

	input = ft_atol(arg);
	if (input < INT_MIN || input > INT_MAX)
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
