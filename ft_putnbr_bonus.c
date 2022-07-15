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

#include "ft_printf_bonus.h"

void	_ft_putnbr(int n, int *count, t_flag flags)
{
	if (n == -2147483648)
	{
		*count += write(1, "-2", 2);
		n = 147483648;
	}
	else if (n < 0)
	{
		*count += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		_ft_putnbr(n / 10, count, flags);
	*count += write(1, &"0123456789"[n % 10], 1);
}

static void	hello(int cond, int a, int *count)
{
	if (cond)
	{
		while(a > 0)
		{
			*count += write (1, " ", 1);
			a--;
		}
	}
}

void	ft_putnbr(int n, int *count, t_flag flags)
{
	int	a;
	int	tf;
	int	prec;


	if (flags.precision && flags.precision_width <= 0 && !n)
		return ;
	prec = flags.precision_width - len_hex(n);
	tf = 0;
	if (prec > 0)
		tf = prec;
	a = flags.width - (len_hex(n) + (flags.space || flags.plus) + tf);
	hello(!flags.minus, a, count);
	if (flags.octo && n)
		*count += write(1, "0x", 2);
	if (flags.plus && n >= 0)
		*count += write(1, "+", 1);
	while (prec > 0)
	{
		*count += write (1, "0", 1);
		prec--;
	}
	if (flags.space && n >= 0 && !flags.plus)
		*count += write(1, " ", 1);
	_ft_putnbr(n, count, flags);
	hello(flags.minus, a, count);
}