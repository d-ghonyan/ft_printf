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

void	ft_putnbr_u(unsigned int n, char c, int *count)
{
	if (c == 'x')
		to_hex_lower(n, count);
	else if (c == 'X')
		to_hex_upper(n, count);
	else
	{
		if (n > 9)
			ft_putnbr_u(n / 10, c, count);
		ft_putchar((n % 10) + 48, count);
	}
}
