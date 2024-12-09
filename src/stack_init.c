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

static int stack_size(int argc, char **argv);
static t_elem   **stack_fill(int argc, char **argv, t_elem **a);
static void add_elem(t_elem **a);

t_elem    **stack_init(int argc, char **argv, t_elem **a)
{
    int size;

    size = stack_size(argc, argv);
    a = ft_calloc(size, sizeof(t_elem *));
    if (!a)
        printerr_exit();
    *a = ft_calloc(1, sizeof(t_elem));
    if (!*a)
    {
        free(a);
        printerr_exit();
    }
    a = stack_fill(argc, argv, a);
    if (argc == 2)
        free_strarray(argv);
    return (a);
}

static int stack_size(int argc, char **argv)
{
    int size;
    int i;

    size = 0;
    i = 1;
    if (argc == 2)
        i = 0;
    while (argv[i])
    {
        i++;
        size++;
    }
    return (size);
}

static t_elem   **stack_fill(int argc, char **argv, t_elem **a)
{
    int i;

    i = 1;
    if (argc == 2)
        i = 0;
    while (argv[i])
    {
        (*a)->value = ft_atoi(argv[i]);
        if (!argv[i + 1])
            break;
        add_elem(a);
        i++;
    }
    stack_start(a);
    return (a);
}

static void add_elem(t_elem **a)
{
    t_elem *new;

    new = ft_calloc(1, sizeof(t_elem));
    if (!new)
        printerr_exit();
    new->prev = *a;
    (*a)->next = new;
    *a = (*a)->next;
}

void stack_start(t_elem **a)
{
    while ((*a)->prev != NULL)
        *a = (*a)->prev;
}