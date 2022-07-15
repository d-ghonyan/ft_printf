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
	*count += write(1, s, ft_strlen(s));
}

void	ft_putstr(char const *s, int *count, t_flag flags)
{
	int	hello;

	hello = flags.width - ft_strlen(s);
	if (flags.minus)
	{
		_ft_putstr(s, count, flags);
		while (hello > 0)
		{
			*count += write(1, " ", 1);
			hello--;
		}
	}
	else
	{
		while (hello > 0)
		{
			*count += write(1, " ", 1);
			hello--;
		}
		_ft_putstr(s, count, flags);
	}
}
