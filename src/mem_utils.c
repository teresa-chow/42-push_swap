/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so  <tchow-so@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:35:56 by tchow-so          #+#    #+#             */
/*   Updated: 2024/12/02 15:35:56 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    free_strarray(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    return ;
}

void    free_stack(t_elem **stack)
{
    t_elem *tmp;

    if (!stack)
        return ;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    free(stack);
    return ;
}