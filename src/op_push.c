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

/* take the top element of one stack and put it at the top of the other
- do nothing if empty */

#include "../include/push_swap.h"

/* move top of b to top of a */
void	pa(t_elem **a, t_elem **b)
{
	if (!b)
		return ;
	(*a)->prev = *b;
	if (!(*b)->next)
		free(b);
	else
	{
		*b = (*b)->next;
		(*b)->prev = NULL;
	}
	(*a)->prev->next = *a;
	*a = (*a)->prev;
	(*a)->prev = NULL;
	write(1, "pa\n", 3);
	return ;
}

/* move top of a to top of b */
void	pb(t_elem **a, t_elem **b)
{
	if (!b)
		return ;
	if (!(*b)->prev)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
	{
		(*b)->prev = *a;
		*a = (*a)->next;
		(*b)->prev->next = *b;
		*b = (*b)->prev;
	}
	(*a)->prev = NULL;
	write(1, "pb\n", 3);
	return ;
}
