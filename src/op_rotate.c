/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:51 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:55:06 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*shift up all elements of a stack by 1 - 1st becomes last*/

#include "../include/push_swap.h"

static void	rotate(t_elem **stack)
{
	t_elem	*last;

	last = stack_last(stack);
	(*stack)->prev = last;
	last->next = *stack;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_elem **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_elem **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_elem **a, t_elem **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return ;
}
