#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l >= 10)
	{
		ft_putnbr_fd((l / 10), fd);
		ft_putnbr_fd((l % 10), fd);
	}
	else
		ft_putchar_fd(l + 48, fd);
}
