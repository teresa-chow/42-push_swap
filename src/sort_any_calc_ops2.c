/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any_calc_ops2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:03 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 12:10:52 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sum_ops(t_moves *option)
{
	option->cost += option->ra;
	option->cost += option->rra;
	option->cost += option->rb;
	option->cost += option->rrb;
	option->cost += option->rr;
	option->cost += option->rrr;
}

void	choose_option(t_moves option, t_moves *moves)
{
	moves->ra = option.ra;
	moves->rra = option.rra;
	moves->rb = option.rb;
	moves->rrb = option.rrb;
	moves->rr = option.rr;
	moves->rrr = option.rrr;
	moves->target = option.target;
	moves->cost = option.cost;
}
