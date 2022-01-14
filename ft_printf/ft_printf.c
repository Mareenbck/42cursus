/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:07:20 by mbascuna          #+#    #+#             */
/*   Updated: 2021/12/14 10:49:29 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

int	is_include(char c, char *type)
{
	int	i;

	i = 0;
	while (type[i])
	{
		if (c == type[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_function(va_list args, const char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_putnbruns(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_hexa(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (format == 'X')
		ft_hexa(va_arg(args, unsigned int), count, "0123456789ABCDEF");
	else if (format == 'p')
	{
		ft_putstr("0x", count);
		ft_pointeur(va_arg(args, size_t), count, "0123456789abcdef");
	}
	else if (format == '%')
		ft_putchar('%', count);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	char	*type;

	type = "cspdiuxX%";
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &count);
		else if (format[i] == '%' && is_include(format[i + 1], type))
		{
			i++;
			ft_function(args, format[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
