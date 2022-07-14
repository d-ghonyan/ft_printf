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

void	ft_putstr(char const *s, int *count, t_flag flags)
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

// void	ft_putstr(char const *s, int *count, t_flag flags)
// {
// 	if (flags.minus)
// 	{
// 		_ft_putstr(s, count, flags);
// 		while (flags.width > 0)
// 		{
// 			ft_putchar(' ', count, flags);
// 			flags.width--;
// 		}
// 	}
// 	else
// 	{
// 		while (flags.width > 0)
// 		{
// 			ft_putchar(' ', count, flags);
// 			flags.width--;
// 		}
// 		_ft_putstr(s, count, flags);
// 	}
// }
