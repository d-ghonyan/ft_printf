/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:45:09 by dghonyan          #+#    #+#             */
/*   Updated: 2022/03/27 17:46:32 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	norm(char const *s, int i, va_list args, int *c)
{
	if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr(va_arg(args, int), c);
	else if (s[i] == 'c')
		ft_putchar(va_arg(args, int), c);
	else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), s[i], c);
	else if (s[i] == 's')
		ft_putstr(va_arg(args, char *), c);
	else if (s[i] == 'p')
		print_ptr(va_arg(args, uintptr_t), c);
	else if (s[i] == '%')
		ft_putchar('%', c);
	else
	{
		ft_putchar('%', c);
		ft_putchar(s[i], c);
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			norm(s, i, args, &c);
		}
		else
			ft_putchar(s[i], &c);
		i++;
	}
	va_end(args);
	return (c);
}
