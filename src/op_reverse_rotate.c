/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:39:50 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/08 17:58:34 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*shift down all elements of a stack by 1 - last becomes first*/

#include "../include/push_swap.h"

static void	reverse_rotate(t_elem **stack)
{
	t_elem	*last_node;

	last_node = stack_last(stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev->next = NULL;
	*stack = last_node;
	(*stack)->prev = NULL;
}

void	rra(t_elem **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_elem **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_elem **a, t_elem **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	return ;
}
