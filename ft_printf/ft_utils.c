/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:01:54 by mbascuna          #+#    #+#             */
/*   Updated: 2021/12/03 19:17:32 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
	}
	if (nb <= 9)
		ft_putchar((nb + '0'), count);
	else
	{
		ft_putnbr((nb / 10), count);
		ft_putchar((nb % 10) + '0', count);
	}
}

void	ft_putnbruns(unsigned int n, int *count)
{
	unsigned int	nb;

	nb = n;
	if (nb <= 9)
		ft_putchar((nb + '0'), count);
	else
	{
		ft_putnbr((nb / 10), count);
		ft_putchar((nb % 10) + '0', count);
	}
}

void	ft_hexa(unsigned int n, int *count, char *base)
{
	if (n < 16)
		ft_putchar(base[n], count);
	else
	{
		ft_hexa((n / 16), count, base);
		ft_putchar(base[(n % 16)], count);
	}
}

void	ft_pointeur(size_t n, int *count, char *base)
{
	if (n < 16)
		ft_putchar(base[n], count);
	else
	{
		ft_pointeur((n / 16), count, base);
		ft_putchar(base[(n % 16)], count);
	}
}
