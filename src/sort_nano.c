/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:28:33 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 12:25:37 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_nano(int size, t_elem **a, t_elem **b)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	return ;
}

void	sort_two(t_elem **a)
{
	if (!sort_check(a))
		sa(a);
	return ;
}

void	sort_three(t_elem **a)
{
	t_elem	*max;

	if (sort_check(a))
		return ;
	max = stack_max(a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->next)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
	return ;
}

void	sort_four(t_elem **a, t_elem **b)
{
	t_elem	*min;
	t_elem	*last;

	if (sort_check(a))
		return ;
	min = stack_min(a);
	last = stack_last(a);
	while ((*a != min) && (last != min))
		ra(a);
	if (last == min)
		rra(a);
	if (sort_check(a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
	return ;
}

void	sort_five(t_elem **a, t_elem **b)
{
	t_elem	*min;
	t_elem	*last;

	if (sort_check(a))
		return ;
	min = stack_min(a);
	last = stack_last(a);
	while ((*a != min) && (last != min) && (last->prev != min))
		ra(a);
	if (last->prev == min)
		rra(a);
	if (last == min)
		rra(a);
	if (sort_check(a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
	return ;
}
