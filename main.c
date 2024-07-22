/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:11 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/22 17:38:52 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is a program that sorts data on a stack,
with a limited set of instructions. */

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (write(2, "Error\n", 6));
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (stack_size(a) == 2) //create spare function sort_stack for these different scenarios ?
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		sort_any(&a, &b);
	//TODO
}
