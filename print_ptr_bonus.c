/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:17 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:18 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	to_hex_lower_p(unsigned long int n, int is_upper, int *count, t_flag flags)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		to_hex_lower_p(n / 16, is_upper, count, flags);
	ft_putchar(hex[n % 16], count, flags);
}

void	print_ptr(uintptr_t ptr, int *count, t_flag flags)
{
	ft_putstr("0x", count, flags);
	to_hex_lower_p(ptr, 0, count, flags);
}
