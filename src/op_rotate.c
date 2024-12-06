/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:51 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/08 17:57:28 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*shift up all elements of a stack by 1 - 1st becomes last*/

#include "../include/push_swap.h"

static void	rotate(t_elem **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = stack_last(stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
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