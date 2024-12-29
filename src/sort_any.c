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

static void find_median(t_elem **a, int size);
static void push_median(t_elem **a, t_elem **b, int size);

void	sort_any(t_elem **a, t_elem **b)
{
    int size;

    size = stack_size(a);
    find_median(a, size);
    push_median(a, b, size);
}

static void push_median(t_elem **a, t_elem **b, int size)
{
    t_elem  *median;

    median = *a;
    while (median->median != 1)
        median = median->next;
    while ((*a)->val != median->val)
    {
        if (median->i < size / 2)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
}

static void find_median(t_elem **a, int size)
{
    t_elem  *dup;
    t_elem  *tail;
    t_elem  *median;
    t_elem  *current;
    int median_i;

    dup = ft_calloc(1, sizeof(t_elem));
    stack_dup(a, &dup);
    tail = stack_last(&dup);
    quicksort(&dup, dup, tail);
    median_i = size / 2;
    while (dup && median_i--)
    {
            median = dup;
            dup = dup->next;
    }
    current = *a;
    while (current->val != median->val)
        current = current->next;
    current->median = 1;
    free_stack(&dup);
}