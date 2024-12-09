/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:37:36 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/09 14:37:39 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    stack_init_b(t_elem **b)
{
    b = ft_calloc(1, sizeof(t_elem *));
    if (!b)
        printerr_exit();
    *b = ft_calloc(1, sizeof(t_elem));
    if (!*b)
    {
        free(b);
        printerr_exit();
    }
    return ;
}