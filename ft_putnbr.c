/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:40:45 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:40:50 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_ft_putnbr(int n, int *count, t_flag flags)
{
	if (n == -2147483648)
	{
		ft_putstr("-2", count, flags);
		n = 147483648;
	}
	else if (n < 0)
	{
		ft_putchar('-', count, flags);
		n *= -1;
	}
	if (n > 9)
		_ft_putnbr(n / 10, count, flags);
	ft_putchar((n % 10) + 48, count, flags);
}

void	ft_putnbr(int n, int *count, t_flag flags)
{
	if (flags.plus && n >= 0)
		ft_putchar('+', count, flags);
	else if (flags.space && n >= 0)
		ft_putchar(' ', count, flags);
	_ft_putnbr(n, count, flags);
}
