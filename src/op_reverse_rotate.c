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

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!stack || !stack->next)
		return ;
	*last_node = stack_last(**stack);
	(*stack)->prev = last_node;
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	return ;
}
