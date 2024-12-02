/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:09:39 by tchow-so          #+#    #+#             */
/*   Updated: 2024/03/29 15:26:13 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char spec, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

static int	ft_print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_printchar(va_arg(ap, int));
	else if (spec == 's')
		count = ft_printstr(va_arg(ap, char *));
	else if (spec == 'p')
		count = ft_printptr((unsigned long)va_arg(ap, unsigned long));
	else if (spec == 'd' || spec == 'i')
		count = ft_printint(spec, (long)va_arg(ap, int), 10);
	else if (spec == 'u')
		count = ft_printint(spec, (long)va_arg(ap, unsigned int), 10);
	else if (spec == 'x' || spec == 'X')
		count = ft_printint(spec, (long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &spec, 1);
	return (count);
}
