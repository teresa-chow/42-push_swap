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
	t_elem	*current;
	int	size;

	if (!stack)
		return (0);
	current = *stack;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_elem	*stack_last(t_elem **stack)
{
	int				last_index;
	t_elem	*current;
	t_elem	*last_node;

	last_index = list_size(stack) - 1;
	current = *stack;
	while (last_index--)
		current = current->next;
	last_node = current;
	return (last_node);
}

t_elem	*stack_max(t_elem **stack)
{
	int				max;
	t_elem	*current;
	t_elem	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	current = *stack;
	while (current != NULL)
	{
		if (current->value > max)
		{
			max = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

t_elem	*stack_min(t_elem **stack)
{
	int				min;
	t_elem	*current;
	t_elem	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	current = *stack;
	min_node = NULL;
	while (current != NULL)
	{
		if (current->value < min)
		{
			min = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}