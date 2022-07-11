/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:26 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:27 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_to_hex_lower(unsigned int n, int *count, t_flag flags)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		_to_hex_lower(n / 16, count, flags);
	ft_putchar(hex[n % 16], count, flags);
}

void	to_hex_lower(unsigned int n, int *count, t_flag flags)
{
	if (flags.octo && n)
		ft_putstr("0x", count, flags);
	_to_hex_lower(n, count, flags);
}
