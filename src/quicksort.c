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

static int  qs_partition(char **str, int low, int high);
static void    qs_swap(int *a, int *b);

quicksort()
{}

static int qs_partition(char **str, int low, int high)
{
    int pivot;
    int i;
    int j;

    i = low;
    j = high;
    while (i < j)
    
}

static void    qs_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}