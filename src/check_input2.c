/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:22:13 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:46:08 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_nodup(int argc, char **argv)
{
	int	i;
	int	cmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		cmp = i + 1;
		while (argv[cmp])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[cmp]))
			{
				if (argc == 2)
					free_strarray(argv);
				printerr_exit();
			}
			cmp++;
		}
		i++;
	}
	return ;
}

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

void	printerr_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
