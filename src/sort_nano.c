/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:28:33 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/25 15:08:21 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_nano(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	return ;
}

void	sort_two(t_stack_node **a)
{
	if (!check_sort(a))
		sa(a);
	return ;
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

	if (check_sort(a))
		return ;
	*max_node = stack_max(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	return ;
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	t_stack_node	*last_node;

	if (check_sort(a))
		return ;
	*min_node = stack_min(*a);
	*last_node = stack_last(*a);
	while ((*a != *min_node) && (*min_node != *last_node))
		ra(a);
	if (*min_node == *last_node)
		rra(a);
	if (check_sort(a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
	return ;
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	t_stack_node	*last_node;

	if (check_sort(a))
		return ;
	*min_node = stack_min(*a);
	*last_node = stack_last(*a);
	while ((*a != *min_node) && (*min_node != *last_node)
		&& (*min_node != (*last_node)->prev))
		ra(a);
	while ((*min_node == *last_node) || (*min_node == (*last_node)->prev))
		rra(a);
	if (check_sort(a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
	return ;
}
