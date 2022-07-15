#include "ft_printf_bonus.h"

int	len(int num, char c)
{
	int	a;
	int	base;

	a = 0;
	base = 10;
	if (c == 'x' || c == 'X')
		base = 16;
	while (num)
	{
		a++;
		num /= base;
	}
	return (a);
}