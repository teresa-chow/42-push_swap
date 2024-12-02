/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:16:05 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/08 18:01:42 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack_node **stack)
{
	int	node_count;

	node_count = 0;
	if (!stack)
		return (0);
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		node_count++;
	}
	return (node_count);
}

t_stack_node	*stack_last(t_stack_node **stack)
{
	int				last_index;
	t_stack_node	*last_node;

	last_index = stack_size(**stack) - 1;
	while (last_index--)
		*stack = (*stack)->next;
	last_node = *stack;
	return (*last_node);
}

t_stack_node	*stack_max(t_stack_node **stack)
{
	int				max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack->next)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*stack_min(t_stack_node **stack)
{
	int				min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack->next)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
