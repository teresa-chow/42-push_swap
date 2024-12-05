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

int	list_size(t_elem **stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 1;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		size++;
	}
	stack_start(stack);
	return (size);
}

/*t_elem	*stack_last(t_elem **stack)
{
	int				last_index;
	t_elem	*last_node;

	last_index = stack_size(**stack) - 1;
	while (last_index--)
		*stack = (*stack)->next;
	last_node = *stack;
	return (*last_node);
}

t_elem	*stack_max(t_elem **stack)
{
	int				max;
	t_elem	*max_node;

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

t_elem	*stack_min(t_elem **stack)
{
	int				min;
	t_elem	*min_node;

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
}*/
