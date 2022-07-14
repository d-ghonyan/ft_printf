#include "ft_printf_bonus.h"

void	width_not_minus(t_flag flags, char c, int *count, char const *s)
{
	int		a;
	int		tf;
	char	hey;

	hey = ' ';
	tf = flags.width - ft_strlen(s);
	if (c == 'c')
		tf = flags.width - 1;
	a = flags.width;
	if(flags.precision_width > 0)
		a = flags.width - flags.precision_width;
	if (!flags.minus)
	{
		if (((c == 's') || (c == 'c')))
		{
			while (tf > 0)
			{
				ft_putchar(' ', count, flags);
				tf--;
			}
		}
		else
		{
			if (flags.zero)
				hey = '0';
			while (a > 0)
			{
				ft_putchar(hey, count, flags);
				a--;
			}
		}
	}
}

void	width_minus(t_flag flags, char c, int *count, char const *s)
{
	int		a;
	char	hey;
	int		tf;

	tf = flags.width - ft_strlen(s);
	if (c == 'c')
		tf = flags.width - 1;
	hey = ' ';
	a = flags.width;
	if(flags.precision_width > 0)
		a = flags.width - flags.precision_width;
	if (flags.minus)
	{
		if (((c == 's' && flags.width > ft_strlen(s))|| (c == 'c' && flags.width > 1)))
		{
			while (flags.width > 0)
			{
				ft_putchar(' ', count, flags);
				flags.width--;
			}
		}
		else
		{
			if (flags.zero)
				hey = '0';
			while (a > 0)
			{
				ft_putchar(hey, count, flags);
				a--;
			}
		}
	}
}