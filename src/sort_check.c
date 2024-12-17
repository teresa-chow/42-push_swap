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

#include "../include/push_swap.h"

int	sort_check(t_elem **stack)
{
	t_elem	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}