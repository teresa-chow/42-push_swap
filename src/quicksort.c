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

static t_elem   *qs_partition(t_elem *head, t_elem *tail);
static void    qs_swap(t_elem *x, t_elem *y);

void    quicksort(t_elem **stack, t_elem *head, t_elem *tail)
{
    t_elem  *pivot;

    if (head && tail && (head != tail) && (head != tail->next))
    {
        pivot = qs_partition(head, tail);
        quicksort(stack, head, pivot->prev);
        quicksort(stack, pivot->next, tail);
    }
}

static t_elem *qs_partition(t_elem *start, t_elem *end)
{
    int  pivot;
    t_elem  *i;
    t_elem  *j;

    pivot = end->val;
    i = start->prev;
    j = start;
    while (j != end)
    {
        if (j->val <= pivot)
        {
            if (i == NULL)
                i = start;
            else
                i = i->next;
            qs_swap(i, j);
        }
        j = j->next;
    }
    if (i == NULL)
        i = start;
    else
        i = i->next;
    qs_swap (i, end);
    return (i);
}

static void    qs_swap(t_elem *x, t_elem *y)
{
    int tmp;

    tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}

void   stack_dup(t_elem **stack, t_elem **dup)
{
    t_elem  *current;
    t_elem  *curr_dup;

    current = *stack;
    curr_dup = *dup;
    while (current)
    {
        curr_dup->val = current->val;
        if (current->next == NULL)
            break ;
        add_elem(curr_dup);
        curr_dup = curr_dup->next;
        current = current->next;
    }
    return ;
}