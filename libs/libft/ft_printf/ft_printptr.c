/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:47:23 by tchow-so          #+#    #+#             */
/*   Updated: 2023/11/17 09:47:15 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex(unsigned long n);
static int	ft_hexlen(unsigned long n);

int	ft_printptr(unsigned long n)
{
	if (!n)
		return (ft_printstr("(nil)"));
	ft_printstr("0x");
	ft_printhex(n);
	return (ft_hexlen(n) + 2);
}

static void	ft_printhex(unsigned long n)
{
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
		ft_printchar(symbols[n]);
	else
	{
		ft_printhex(n / 16);
		ft_printchar(symbols[n % 16]);
	}
}

static int	ft_hexlen(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		++count;
	}
	return (count);
}
