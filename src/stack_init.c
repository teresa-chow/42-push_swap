/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:23:48 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/29 15:29:32 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void   stack_fill(int argc, char **argv, t_elem **a);

void    stack_init(int argc, char **argv, t_elem **a)
{
    *a = ft_calloc(1, sizeof(t_elem));
    if (!*a)
    {
        free(a);
        printerr_exit();
    }
    stack_fill(argc, argv, a);
    if (argc == 2)
        free_strarray(argv);
    return ;
}

static void   stack_fill(int argc, char **argv, t_elem **a)
{
    int i;
    int index;
    t_elem  *current;

    i = 1;
    if (argc == 2)
        i = 0;
    current = *a;
    index = 0;
    while (argv[i])
    {
        current->val = ft_atoi(argv[i]);
        current->i = index;
        if (!argv[i + 1])
            break;
        add_elem(current);
        current = current->next;
        i++;
        index++;
    }
    return ;
}

void add_elem(t_elem *elem)
{
    t_elem *new;

    new = ft_calloc(1, sizeof(t_elem));
    if (!new)
        printerr_exit(); //should free previously alloc'ed nodes
    elem->next = new;
    new->prev = elem;
    elem = new;
}