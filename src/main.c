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
	t_elem	**b;
	int	size;

	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv = check_input(argc, argv);
	a = stack_init(argc, argv, a);
	b = ft_calloc(1, sizeof(t_elem *));
	size = list_size(a);
	if (!sort_check(a))
	{
		if (size >= 2 && size <= 5)
			sort_nano(a, b);
		/*while ((*a)->next != NULL) //test only
		{
			printf("(*a)->value: %d\n", (*a)->value);
			*a = (*a)->next;
		}
		printf("(*a)->value: %d\n", (*a)->value);
		stack_start(a); //test only*/
		/*else
			sort_any(a, b);*/
	}
	free(b);
	//free_stack(a);
	return (0);
}
