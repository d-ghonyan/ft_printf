/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:40:59 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:01 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags)
{
	if (c == 'x')
		to_hex_lower(n, count, flags);
	else if (c == 'X')
		to_hex_upper(n, count, flags);
	else
	{
		if (n > 9)
			_ft_putnbr_u(n / 10, c, count, flags);
		ft_putchar((n % 10) + 48, count, flags);
	}
}

void	ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags)
{
	if (c == 'u')
	{
		if (flags.plus && n)
			ft_putchar('+', count, flags);
		else if (flags.space)
			ft_putchar(' ', count, flags);
	}
	_ft_putnbr_u(n, c, count, flags);
}
