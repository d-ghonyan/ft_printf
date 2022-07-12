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

#include "ft_printf_bonus.h"

static int	thingie_(t_flag flags)
{
	return (flags.octo == 0
		&& flags.plus == 0
		&& flags.space == 0
		&& flags.minus == 0
		&& flags.precision == 0
		&& flags.width == 0);
}

static void	thingie(t_flag *flags)
{
	flags->octo = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->precision = 0;
	flags->precision_width = -1;
	flags->width = -1;
}

static void	norm(char s, va_list args, int *c, t_flag flags)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), c, flags);
	else if (s == 'c')
		ft_putchar(va_arg(args, int), c, flags);
	else if (s == 'x' || s == 'X' || s == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), s, c, flags);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), c, flags);
	else if (s == 'p')
		print_ptr(va_arg(args, uintptr_t), c, flags);
	else if (s == '%')
		ft_putchar('%', c, flags);
	else if (thingie_(flags))
	{
		ft_putchar('%', c, flags);
		ft_putchar(s, c, flags);
	}
}

static void	another_thingie(t_flag flags, char c, int *count)
{
	if (!ft_strchr("cspiduxX%", c))
	{
		ft_putchar('%', count, flags);
		if (flags.octo)
			ft_putchar('#', count, flags);
		if (flags.plus)
			ft_putchar('+', count, flags);
		if (flags.space)
			ft_putchar(' ', count, flags);
		if (flags.precision)
			ft_putchar('.', count, flags);
		if (flags.width)
			ft_putnbr(flags.width, count, flags);
		if (flags.minus)
			ft_putchar('-', count, flags);
		if (flags.zero)
			ft_putchar('0', count, flags);
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		c;
	t_flag	flags;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i])
	{
		thingie(&flags);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			eh(&flags, &i, s);
			printf("%d", flags.width);
			//width(flags, s[i]);
			another_thingie(flags, s[i], &c);
			norm(s[i], args, &c, flags);
		}
		else
			ft_putchar(s[i], &c, flags);
		i++;
	}
	va_end(args);
	return (c);
}

int main()
{
	// printf("--%-120s--\n", "1123");
	ft_printf("--%120s----\n", "1123");
	// ft_printf("aaaaaaaa  %0s  aaaaaa\n", 123);
}