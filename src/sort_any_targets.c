/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any_targets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:46:03 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/12 13:46:03 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int check_max(t_info *info, t_elem *elem);

void find_key_values(int size, t_elem **a, t_info *info)
{
    t_elem  *dup;
    t_elem  *tail;
    t_elem  *current;

    dup = ft_calloc(1, sizeof(t_elem));
    stack_dup(a, &dup);
    tail = stack_last(&dup);
    quicksort(&dup, dup, tail);
    set_info(dup, info, size);
    current = *a;
    while (current->val != info->median)
        current = current->next;
    current->median = 1;
    free_stack(&dup);
}

void set_info(t_elem *dup, t_info *info, int size)
{
    int i;
    int median_i;
    t_elem  *median;
    t_elem  *max;

    info->size = size;
    info->min = dup->val;
    max = stack_last(&dup);
    i = 0;
    while (i < 5)
    {
        info->max[i] = max->val;
        max = max->prev;
        i++;
    }
    median_i = size / 2;
    while (dup && median_i--)
    {
            median = dup;
            dup = dup->next;
    }
    info->median = median->val;
}

void push_median(t_elem **a, t_elem **b, int size)
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

void    push_presort(t_info *info, t_elem **a, t_elem **b)
{
    while (*a)
    {
        if (!check_max(info, *a))
        {
            pb(a, b);
            if ((*b)->val < info->median)
                rb(b);
        }
        else
            ra(a);
        if (stack_size(a) == 5)
            break ;
    }
}

static int check_max(t_info *info, t_elem *elem)
{
    if (elem->val == info->max[0])
        return (1);
    else if(elem->val == info->max[1])
        return (1);
    else if(elem->val == info->max[2])
        return (1);
    else if(elem->val == info->max[3])
        return (1);
    else if(elem->val == info->max[4])
        return (1);
    else
        return (0);
}