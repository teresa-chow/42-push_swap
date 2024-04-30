/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:23:48 by tchow-so          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:45 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/* atol is used here to check eventual overflows
converting every string into a long value */
static long	ft_atol(const char *str)
{
	long	num;
	int	isneg;
	int	i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
		|| str [i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f'))
	
}
