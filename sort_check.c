/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:46:08 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/22 15:53:55 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// sort_rev_check
