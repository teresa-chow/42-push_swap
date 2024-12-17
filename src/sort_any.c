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

static void find_median(t_elem **a, t_elem **median, int size);

void	sort_any(t_elem **a, t_elem **b)
{
    int size;
    t_elem  *median;

    (void)b;
    size = stack_size(a);
    find_median(a, &median, size);
    //push median to stack b
}

static void find_median(t_elem **a, t_elem **median, int size)
{
    t_elem  *dup;
    t_elem  *tail;
//    int median_i;

    (void)size;
    (void)median;
    dup = ft_calloc(1, sizeof(t_elem));
    stack_dup(a, &dup);
    tail = stack_last(&dup); // OK until this point
    quicksort(dup, tail);
/*    median_i = size / 2;
    while (dup && median_i--)
    {
            *median = dup;
            dup = dup->next;
    } */
    free_stack(&dup);
}