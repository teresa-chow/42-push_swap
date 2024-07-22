/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:16:05 by tchow-so          #+#    #+#             */
/*   Updated: 2024/06/06 11:18:59 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	last_index;
	t_stack_node	*last_node;

	last_index = stack_size(**stack) - 1;
	while (last_index--)
		*stack = (*stack)->next;
	last_node = *stack;
	return (*last_node);
}
