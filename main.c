/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:11 by tchow-so          #+#    #+#             */
/*   Updated: 2024/04/29 15:13:08 by tchow-so         ###   ########.fr       */
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
	stack_init(&a, argv + 1, argc == 2); //TODO
	if (!stack_sorted(a)) //TODO
	{
		if (stack_len(a) == 2) //TODO
			sa(&a, false); //TODO
		else if (stack_len(a) == 3)
			tiny_sort(&a); //TODO
		else
			push_swap(&a, &b);
	}
	free_stack(&a); //TODO
}
