/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any_calc_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:03 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 12:18:55 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_next_elem(t_elem **a, t_elem *b);
static void	calc_rotate_b(int i, int size, t_moves *moves);
static void	calc_rotate_a(t_elem **a, t_moves *moves);
static void	calc_rotate_both(t_moves *moves);

void	calc_ops(t_elem **a, t_elem **b, t_moves *moves)
{
	int		i;
	int		size_b;
	t_elem	*current_b;
	t_moves	option;

	size_b = stack_size(b);
	current_b = *b;
	i = 0;
	while (current_b)
	{
		ft_bzero(&option, sizeof(t_moves));
		calc_rotate_b(i, size_b, &option);
		option.target = find_next_elem(a, current_b);
		calc_rotate_a(a, &option);
		calc_rotate_both(&option);
		sum_ops(&option);
		if (option.cost < moves->cost)
			choose_option(option, moves);
		current_b = current_b->next;
		i++;
	}
}

/* Find the smallest element in stack a greater than *b */
static int	find_next_elem(t_elem **a, t_elem *b)
{
	int		target;
	t_elem	*current_a;

	current_a = *a;
	target = INT_MAX;
	while (current_a)
	{
		if ((current_a->val > b->val) && (current_a->val < target))
			target = current_a->val;
		current_a = current_a->next;
	}
	return (target);
}

static void	calc_rotate_b(int i, int size, t_moves *option)
{
	if (i <= size - i)
		option->rb = i;
	else
		option->rrb = size - i;
}

static void	calc_rotate_a(t_elem **a, t_moves *option)
{
	t_elem	*current;
	int		i;
	int		size;

	current = *a;
	i = 0;
	size = stack_size(a);
	while (current && current->val != option->target)
	{
		current = current->next;
		i++;
	}
	if (i <= size - i)
		option->ra = i;
	else
		option->rra = size - i;
}

static void	calc_rotate_both(t_moves *moves)
{
	while ((moves->ra > 0) && (moves->rb > 0))
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while ((moves->rra > 0) && (moves->rrb > 0))
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
}
