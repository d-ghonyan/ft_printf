/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:09 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:10 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	_ft_putstr(char const *s, int *count, t_flag flags)
{
	int		i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count, flags);
		i++;
	}
}

void	ft_putstr(char const *s, int *count, t_flag flags)
{
	if (flags.minus)
	{
		ft_putstr(s, count, flags);
		while (flags.width--)
			ft_putchar(' ', count, flags);
	}
	else
	{
		// printf("%d\n", flags.width);
		while (flags.width > 0)
		{
			ft_putchar('A', count, flags);
			//printf("AS");
			flags.width--;
		}
		ft_putchar(flags.width + 48, count, flags);
		ft_putstr(s, count, flags);
		ft_putchar(9 + 48, count, flags);
		
	}
}
