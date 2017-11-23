#include <unistd.h>
#include "libft.h"

void ft_putnbr(int n)
{
	long l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar('-');
	}
	if (l >= 10)
	{
		ft_putnbr(l / 10);
		ft_putnbr(l % 10);
	}
	else
		ft_putchar(l + 48);
}
