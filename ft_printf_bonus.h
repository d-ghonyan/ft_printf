/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:46:43 by dghonyan          #+#    #+#             */
/*   Updated: 2022/03/27 17:47:42 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_flag
{
	int	plus;
	int	octo;
	int	space;
}	t_flag;


void	to_hex_lower(unsigned int n, int *count, t_flag flags);
void	ft_putnbr(int n, int *count, t_flag flags);
void	ft_putstr(char const *s, int *count, t_flag flags);
void	to_hex_upper(unsigned int n, int *count, t_flag flags);
void	ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags);
void	ft_putchar(char c, int *count, t_flag flags);
void	print_ptr(uintptr_t ptr, int *count, t_flag flags);
void	eh(t_flag *flags, int *i, char const *s);
int		ft_printf(const char *s, ...);

#endif
