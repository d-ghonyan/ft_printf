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


static int	thingie_(t_flag flags)
{
	return (flags.octo == 0
	&& flags.plus == 0
	&& flags.space == 0);
}

static void	thingie(t_flag *flags)
{
	flags->octo = 0;
	flags->plus = 0;
	flags->space = 0;
}

static void	norm(char const *s, int i, va_list args, int *c, t_flag flags)
{
	if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr(va_arg(args, int), c, flags);
	else if (s[i] == 'c')
		ft_putchar(va_arg(args, int), c, flags);
	else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), s[i], c, flags);
	else if (s[i] == 's')
		ft_putstr(va_arg(args, char *), c, flags);
	else if (s[i] == 'p')
		print_ptr(va_arg(args, uintptr_t), c, flags);
	else if (s[i] == '%')
		ft_putchar('%', c, flags);
	else if (thingie_(flags))
	{
		ft_putchar('%', c, flags);
		ft_putchar(s[i], c, flags);
	}
}

void	another_thingie(t_flag flags, char c, int *count)
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
			while (s[i] && ft_strchr("# +", s[i]))
			{
				flags.octo += s[i] == '#';
				flags.plus += s[i] == '+';
				flags.space += s[i] == ' ';
				i++;
			}
			another_thingie(flags, s[i], &c);
			norm(s, i, args, &c, flags);
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
	int n = 765;
	ft_printf("%+#%#+k\n", 1);
	printf("%+#%#+k\n", 1);
	//printf("\n%#+lll\n");
}