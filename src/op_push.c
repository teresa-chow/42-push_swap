/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:38:38 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/29 15:15:09 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*take the top element of one stack and put it at the top of the other
- do nothing if empty*/

#include "../inc/push_swap.h"

/*move top of b to top of a*/
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

/*move top of a to top of b*/
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
