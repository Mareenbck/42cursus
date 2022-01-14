/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:24:23 by mbascuna          #+#    #+#             */
/*   Updated: 2021/12/03 19:25:51 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libc.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *count);
void	ft_putpercent(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbruns(unsigned int n, int *count);
void	ft_hexa(unsigned int n, int *count, char *base);
void	ft_pointeur(size_t n, int *count, char *base);

#endif
