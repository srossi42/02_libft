/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:06:21 by srossi            #+#    #+#             */
/*   Updated: 2017/12/14 18:41:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int x;

	x = 1;
	while (x * x < nb)
		x++;
	return (x);
}

void	ft_display(int size, char **tab)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size - 1)
		{
			ft_putchar(tab[x][y]);
			x++;
		}
		ft_putchar(tab[x][y]);
		ft_putchar('\n');
		y++;
	}
	return ;
}

int	main(int argc, char** argv)
{
	t_list *list;
	int size;
	char **tab;
	char **tab2;
	char **tab3;
	int z;
	//char c=;
	list = NULL;

	if (argc != 2)
		return (0);
//	list = ft_read(argv[1], list);
	//tab = ft_grid(3);
	if ((list = ft_read(argv[1], list)))
	{
		z = ft_lstlen(&list);
		ft_putstr("longueur list  main vaut : ");
		ft_putnbr(z);
		ft_putchar('\n');
		ft_printlist(list);
		size = ft_sqrt(z * 4);
		ft_putstr("size vaut : ");
		ft_putnbr(size);
		ft_putchar('\n');
		tab = ft_grid(size);
		tab2 = ft_grid(size + 1);
		tab3 = ft_grid(size + 2);
		ft_tetri_display(list->content);
	//	ft_putnbr(estValide(list, tab, 0, size));
		if (estValide(list, tab, 0, size, z) == 1)
		{
			ft_putchar('0');
			ft_putchar('\n');
			ft_display(size, tab);
			return (0);
		}

		ft_putchar('1');
		if (estValide(list, tab2, 0, size + 1, z) == 1)
		{
			ft_putchar('1');
			ft_putchar('\n');
			ft_display(size + 1, tab2);
			return (0);
		}
		ft_putchar('2');
		if (estValide(list, tab3, 0, size + 2, z) == 1)
		{
			ft_putchar('2');
			ft_putchar('\n');
			ft_display(size + 2, tab3);
			return (0);
		}
	}
	/*
		{
			size++;
			free(tab);
			tab = ft_grid(size);
		}
	//ft_display(size, tab);
	}*/
	return (0);
}
