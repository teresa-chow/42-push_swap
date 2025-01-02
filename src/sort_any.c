/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:03 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/12 13:46:03 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void    sort_remainder(t_info info, t_elem **a, t_elem **b);
static void    make_moves(t_moves moves, t_elem **a, t_elem **b);
static void    reset_index(t_elem **stack);

void	sort_any(int size, t_elem **a, t_elem **b)
{
    t_info  info;

    ft_bzero(&info, sizeof(t_info));
    find_key_values(size, a, &info);
    push_median(info, a, b);
    push_presort(info, a, b);
    sort_five(a, b);
    sort_remainder(info, a, b);
}

static void    sort_remainder(t_info info, t_elem **a, t_elem **b)
{
    t_moves moves;
    t_elem  *min;

    ft_bzero(&moves, sizeof(t_moves));
    while (*b)
    {
        calc_ops(a, b, &moves);
        make_moves(moves, a, b);
    }
    reset_index(a);
    min = stack_min(a);
    while (*a != min)
    {
        if (min->i < info.size / 2)
            ra(a);
        else
            rra(a);
    }
}

static void make_moves(t_moves moves, t_elem **a, t_elem **b)
{
    while (--moves.rr >= 0)
        rr(a, b);
    while (--moves.rrr >= 0)
        rrr(a, b);
    while (--moves.rb >= 0)
        rb(b);
    while (--moves.rrb >= 0)
        rrb(b);
    while (--moves.ra >= 0)
        ra(a);
    while (--moves.rra >= 0)
        rra(a);
    pa(a, b);
}

static void    reset_index(t_elem **stack)
{
    int i;
    t_elem  *current;

    current = *stack;
    i = 0;
    while (current)
    {
        current->i = i;
        current = current->next;
        i++;
    }
}