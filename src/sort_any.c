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

void	sort_any(int size, t_elem **a, t_elem **b)
{
    t_info  info;

    ft_bzero(&info, sizeof(t_info));
    find_key_values(size, a, &info);
    push_median(a, b, size);
    push_presort(&info, a, b);
    sort_five(a, b);
}