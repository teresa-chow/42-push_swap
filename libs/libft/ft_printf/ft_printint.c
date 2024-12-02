/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:47:23 by tchow-so          #+#    #+#             */
/*   Updated: 2023/11/15 13:03:15 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(char spec, long n, int base)
{
	int		count;
	char	*symbols;

	if (spec == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_printint(spec, -n, base) + 1);
	}
	else if (n < base)
		return (ft_printchar(symbols[n]));
	else
	{
		count = ft_printint(spec, n / base, base);
		return (count + ft_printint(spec, n % base, base));
	}
}
