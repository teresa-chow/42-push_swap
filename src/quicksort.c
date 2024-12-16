/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:07:57 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/13 17:07:57 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_elem *qs_partition(t_elem *head, t_elem *tail);
static void    qs_swap(t_elem *x, t_elem *y);

void    quicksort(t_elem *head, t_elem *tail)
{
    t_elem  *pivot;

    if (!head || !tail)
        return ;
    pivot = qs_partition(head, tail);
    quicksort(head, pivot);
    quicksort(pivot->next, tail);
}

/* Rearrange list values around pivot */
static t_elem *qs_partition(t_elem *start, t_elem *end)
{
    t_elem  *pivot;
    t_elem  *new_pivot;
    t_elem  *current;

    pivot = start;
    new_pivot = start;
    current = start;
    while (current != end->next)
    {
        if (current->val < pivot->val)
        {
            qs_swap(current, new_pivot->next);
            new_pivot = new_pivot->next;
        }
        current = current->next;
    }
    qs_swap(pivot, new_pivot);
    return (new_pivot);
}

static void    qs_swap(t_elem *x, t_elem *y)
{
    int tmp;

    tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}

void   stack_dup(t_elem **stack, t_elem **dup) //ATTENTION: alloc mem
{
    t_elem  *current;

    current = *stack;
    while (current->next)
    {
        *dup = ft_calloc(1, sizeof(t_elem));
        if (!*dup)
        {
            free(dup);
            free(stack);
            printerr_exit();
        }
        *dup = current;
        current = current->next;
        *dup = (*dup)->next;
    }
    return ;
}