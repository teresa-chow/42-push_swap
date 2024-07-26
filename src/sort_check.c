/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:46:08 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/25 16:03:36 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_check(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/*
int	sort_rev_check(t_stack_node **stack) // useful ?
{
	*stack = stack_last(stack);
	while ((*stack)->prev)
	{
		if ((*stack)->value > (*stack)->prev->value)
			return(0);
		*stack = (*stack)->prev;
	}
	return (1);
}*/
