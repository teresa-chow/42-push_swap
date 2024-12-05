/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:11 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/08 17:38:19 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is a program that sorts data on a stack, with a limited
set of instructions. */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	**a;
	//t_elem	**b;

	a = NULL;
	//b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv = check_input(argc, argv);
	a = stack_init(argc, argv, a);
	if (!sort_check(a))
	{
		/*if (stack_size(a) >= 2 && stack_size(a) <= 5)
			sort_nano(a, b);
		else
			sort_any(a, b);*/
	}
	//free_stack
	return (0);
}
