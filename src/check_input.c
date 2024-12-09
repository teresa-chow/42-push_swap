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

static void	check_syntax(char *arg);
static void	check_limits(char *arg);

char	**check_input(int argc, char **argv)
{
	int	i;

	if (argc == 2 && !check_space(argv[1]))
	{
		check_syntax(argv[1]);
		check_limits(argv[1]);
		exit (EXIT_SUCCESS);
	}
	if (argc == 2 && check_space(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			printerr_exit();
		i = 0;
	}
	check_nodup(argc, argv);
	i = 1;
	while (argv[i])
	{
		check_syntax(argv[i]);
		check_limits(argv[i]);
		i++;
	}
	return (argv);
}

static void	check_syntax(char *arg)
{
	int	i;

	if ((arg[0] != '+' && arg[0] != '-') && (!ft_isdigit(arg[0])))
		printerr_exit();
	if ((arg[0] == '+' || arg[0] == '-') && (!ft_isdigit(arg[1])))
		printerr_exit();
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			printerr_exit();
		i++;
	}
	return ;
}

static void	check_limits(char *arg)
{
	long	input;

	input = ft_atol(arg);
	if (input < INT_MIN || input > INT_MAX)
		printerr_exit();
	return ;
}

long	ft_atol(const char *str)
{
	long	result;
	int	sign;
	int	i;

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