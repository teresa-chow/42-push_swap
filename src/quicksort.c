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

void    quicksort(char **str, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = qs_partition(str, low, high);
        quicksort(str, low, pivot - 1);
        quicksort(str, pivot + 1, high);
    }
}

/* sort_any currently only takes two lists as arguments */
static int qs_partition(char **str, int low, int high)
{
    int pivot;
    int i;
    int j;

    i = low;
    j = high;
    while (i < j)
    {
        while (str[i] <= pivot && i <= high - 1)
            i++;
        while (str[j] > pivot && j >= low + 1)
            j--;
        if (i > j)
            qs_swap(&str[i], &str[j]);
    }
    qs_swap(&str[low], &str[j]);
    return (j);
}

static void    qs_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Still needs review for application */