/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:17 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:55:33 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*swap the first 2 elements at the top of a stack*/

#include "../include/push_swap.h"

static void	swap(t_elem **head)
{
	*head = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return ;
}

void	sa(t_elem **a)
{
	swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_elem **b)
{
	swap(b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_elem **a, t_elem **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	return ;
}
