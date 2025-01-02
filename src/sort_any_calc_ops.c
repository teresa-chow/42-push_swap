/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:03 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/12 13:46:03 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int find_next_elem(t_elem **a, t_elem *b);
static void calc_rotate_a (t_elem **a, int target, t_moves *moves);
static void calc_rotate_both(t_moves *moves);

void    calc_ops(t_elem **a, t_elem **b, t_moves *moves)
{
    int size_b;
    int i;
    int  target;
    t_elem  *current_b;

    size_b = stack_size(b);
    current_b = *b;
    i = 0;
    while (current_b && (i < size_b))
    {
        reset_moves(moves);
        target = find_next_elem(a, *b);
        calc_rotate_a(a, target, moves);
        calc_rotate_both(moves);
        current_b = current_b->next;
        i++;
    }
}

/* Find the smallest element in stack a greater than *b,
if not possible, return stack a min element */
static int find_next_elem(t_elem **a, t_elem *b)
{
    //bool    next_higher;
    int     target;
    t_elem  *current_a;
    //t_elem  *min;

    //next_higher = 0;
    current_a = *a;
    target = INT_MAX;
    while (current_a)
    {
        if ((current_a->val > b->val) && (current_a->val < target))
        {
            target = current_a->val;
            //next_higher = 1;
        }
        current_a = current_a->next;
    }
    /*if (!next_higher) // with this algorithm, do we evere get here? top 5 already in stack a
    {
        min = stack_min(a);
        target = min->val;
    }*/
    return (target);
}

/*static void calc_rotate_b (int i, int size, t_moves *moves)
{
        if (i <= size - i)
            moves->rb = i;
        else
            moves->rrb = size - i;
}*/

static void calc_rotate_a (t_elem **a, int target, t_moves *moves)
{
    t_elem *current;
    int i;
    int size;

    current = *a;
    i = 0;
    size = stack_size(a);
    while (current && current->val != target)
    {
        current = current->next;
        i++;
    }
    if (i <= size - i)
        moves->ra = i;
    else
        moves->rra = size - i;
}

static void calc_rotate_both(t_moves *moves)
{
    while (moves->ra && moves->rb)
    {
        moves->ra--;
        moves->rb--;
        moves->rr++;
    }
    while (moves->rra && moves->rrb)
    {
        moves->rra--;
        moves->rrb--;
        moves->rrr++;
    }
}