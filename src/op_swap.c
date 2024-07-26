/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:17 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/25 15:06:55 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*swap the first 2 elements at the top of a stack*/
static void	swap(t_stack_node **head)
{
//	if (!head || !head->next)
//		return ;
	*head = *(head->next);
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return ;
}

void	sa(t_stack_node **a)
{
	if (a && a->next)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	return ;
}

void	sb(t_stack_node **b)
{
	if (b && b->next)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	return ;
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if ((a && a->next) && (b && b->next))
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
	return ;
}
