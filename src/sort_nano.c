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

#include "../include/push_swap.h"

void	sort_nano(t_elem **a, t_elem **b)
{
	int	size;

	size = list_size(a);
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
	if ((*a)->value > (*a)->next->value)
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
	while ((*a != min) && (min != last))
		ra(a);
	if (min == last)
		rra(a);
	if (sort_check(a))
		return ;
	b = ft_calloc(1, sizeof(t_elem *));
	*b = ft_calloc(1, sizeof(t_elem));
	pb(a, b);
	sort_three(a);
	pa(a, b);
	return ;
}

void	sort_five(t_elem **a, t_elem **b) //REVIEW
{
	t_elem	*min;
	t_elem	*last;

	if (sort_check(a))
		return ;
	min = stack_min(a);
	last = stack_last(a);
	while ((*a != min) && (min != last)
		&& (min != last->prev))
		ra(a);
	while ((min == last) || (min == last->prev))
		rra(a);
	if (sort_check(a))
		return ;
	b = ft_calloc(1, sizeof(t_elem *));
	*b = ft_calloc(1, sizeof(t_elem));
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
	return ;
}