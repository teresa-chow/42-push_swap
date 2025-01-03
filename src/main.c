/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:11 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:50:14 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is a program that sorts data on a stack, with a limited
set of instructions. */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	//t_elem	*current; //delete
	int		size;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv = check_input(argc, argv);
	stack_init(argc, argv, &a);
	size = stack_size(&a);
	/*current = a; //delete
	while (current)
	{
		printf("current->val: %d\n", current->val);
		current = current->next;
	}*/
	if (!sort_check(&a))
	{
		if (size >= 2 && size <= 5)
			sort_nano(size, &a, &b);
		else
			sort_any(size, &a, &b);
	}
	/*current = a; //delete
	while (current)
	{
		printf("current->val: %d\n", current->val);
		current = current->next;
	}*/
	free_stack(&a);
	return (0);
}
