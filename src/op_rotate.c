/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:51 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/25 16:15:17 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*shift up all elements of a stack by 1 - 1st becomes last*/

#include "../inc/push_swap.h"

static void rotate(t_stack_node **stack)
{
//	if (!stack || !stack->next)
//		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = stack_last(**stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	ra(t_stack_node **a)
{
	if (a && a->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	return ;
}

void	rb(t_stack_node **b)
{
	if (b && b->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	return ;
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if ((a && a->next) && (b && b->next))
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	return ;
}
