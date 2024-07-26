/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:38:38 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/25 16:03:08 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*take 1st element at top of b and put at top of a - do nothing if empty*/
void	pa(t_stack_node **a, t_stack_node **b)
{
	if ((a && a->next) && (b && b->next))
	{
		(*a)->prev = *b;
		(*a)->prev->next = *a;
		*a = (*a)->prev;
		(*a)->prev = NULL;
		*b = (*b)->next;
		(*b)->prev = NULL;
		write(1, "pa\n", 3);
	}
	return ;
}

/*take 1st element at top of a and put at top of b - do nothing if empty*/
void	pb(t_stack_node **a, t_stack_node **b)
{
	if ((a && a->next) && (b && b->next))
	{
		(*b)->prev = *a;
		(*b)->prev->next = *b;
		*b = (*b)->prev;
		(*b)->prev = NULL;
		*a = (*a)->next;
		(*a)->prev = NULL;
		write(1, "pb\n", 3);
	}
	return ;
}
