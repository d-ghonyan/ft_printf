#include "ft_printf_bonus.h"

int	len(int num)
{
	int	a;

	a = 0;
	if (!num)
		return (1);
	while (num)
	{
		a++;
		num /= 10;
	}
	return (a);
}

int	len_hex(unsigned int num)
{
	int	a;

	a = 0;
	if (!num)
		return (1);
	while (num)
	{
		a++;
		num /= 16;
	}
	return (a);
}

int	len_ptr(uintptr_t num)
{
	uintptr_t	a;

	a = 0;
	if (!num)
		return (1);
	while (num)
	{
		a++;
		num /= 16;
	}
	return (a);
}

