/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:38:57 by jlemahie          #+#    #+#             */
/*   Updated: 2017/12/13 16:40:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

char	**ft_grid(int size)  // Creer le carre rempli de points
{
	char	**tab;
	int		x;
	int		y;

		tab = malloc(sizeof(char*) * (size + 2));
		y = 0;
		while (y < size)
		{
			tab[y] = malloc(sizeof(char) * (size + 2));
			x = 0;
			while (x < size)
			{
				tab[y][x] = '.';
				x++;
			}
			tab[y][x] = 'x';
			x++;
			tab[y][x] = 'x';
			y++;
		}
		while (y < size + 2)
		{
			tab[y] = malloc(sizeof(char) * (size + 2));
			x = 0;
			while (x < size)
			{
				tab[y][x] = 'x';
				x++;
			}
			tab[y][x] = 'x';
			x++;
			tab[y][x] = 'x';
			y++;
		}
	return (tab);
}

/*char	**ft_regrid(int size, char **tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
			x++;
		tab[y][x] = 'x';
		x++;
		tab[y][x] = 'x';
		y++;
	}
	while (y < size + 2)
	{
		x = 0;
		while (x < size)
		{
			tab[y][x] = 'x';
			x++;
		}
		tab[y][x] = 'x';
		x++;
		tab[y][x] = 'x';
		y++;
	}
	return (tab);
}*/

int	placable(t_tetri piece, char **tab, int x, int y)
{
//	tab = ft_regrid(4, tab);
		if (tab[x + piece.t1.x][y + piece.t1.y] == '.' &&
				tab[x + piece.t2.x][y + piece.t2.y] == '.' &&
				tab[x + piece.t3.x][y + piece.t3.y] == '.' &&
				tab[x + piece.t4.x][y + piece.t4.y] == '.' &&
				/*piece.place == 0*/)
			return (1);
		return (0);
}

int estValide (t_tetri **piece, char **tab, int pos, int size)
{
	int	x;
	int	y;

	if (pos == size*size)
	{
//		if (piece[0].place == 1 && piece[1].place == 1 && piece[2].place == 1 && piece[3].place == 1)
			return (1);
//		else
//		{
//			return (0);
//		}
	}
	x = pos/size;
	y = pos%size;
	if (tab[x][y] != '.')
		return (estValide(piece, tab, pos + 1, size, 0));
	while (pos < size*size)
	{
		x = pos/size;
		y = pos%size;
		if (placable(piece[i], tab, x, y))
		{
			tab[x + piece[i].t1.x][y + piece[i].t1.y] = piece[i].id;
			tab[x + piece[i].t2.x][y + piece[i].t2.y] = piece[i].id;
			tab[x + piece[i].t3.x][y + piece[i].t3.y] = piece[i].id;
			tab[x + piece[i].t4.x][y + piece[i].t4.y] = piece[i].id;
			piece[i].place = 1;
			if ((estValide (piece, tab, 0, size, i + 1)) == 1)
				return (1);
			else
			{
				tab[x + piece[i].t1.x][y + piece[i].t1.y] = '.';
				tab[x + piece[i].t2.x][y + piece[i].t2.y] = '.';
				tab[x + piece[i].t3.x][y + piece[i].t3.y] = '.';
				tab[x + piece[i].t4.x][y + piece[i].t4.y] = '.';
				piece[i].place = 0;
//				tab = ft_regrid(size, tab);
			}
		}
		pos++;
	}
	return (42);
}

/*int	ft_check(t_tetri *piece, int nbrPieces)
{
	int i;

	i = 0;
	while (i < nbrPieces)
	{
		if (piece[i].place == 0)
			return (0);
		i++;
	}
	return (1);
}*/
/*
int main(void)
{
	t_tetri *pieces;
	char **tab;
//1
	pieces[0].t1.x = 0;
	pieces[0].t1.y = 0;
	pieces[0].t2.x = 1;
	pieces[0].t2.y = 0;
	pieces[0].t3.x = 1;
	pieces[0].t3.y = 1;
	pieces[0].t4.x = 1;
	pieces[0].t4.y = 2;
	pieces[0].id = 'A';
	pieces[0].place = 0;
//3
	pieces[1].t1.x = 0;
	pieces[1].t1.y = 0;
	pieces[1].t2.x = 1;
	pieces[1].t2.y = 0;
	pieces[1].t3.x = 2;
	pieces[1].t3.y = 0;
	pieces[1].t4.x = 3;
	pieces[1].t4.y = 0;
	pieces[1].id = 'B';
	pieces[1].place = 0;
//2
	pieces[2].t1.x = 0;
	pieces[2].t1.y = 0;
	pieces[2].t2.x = 0;
	pieces[2].t2.y = 1;
	pieces[2].t3.x = 1;
	pieces[2].t3.y = 1;
	pieces[2].t4.x = 2;
	pieces[2].t4.y = 1;
	pieces[2].id = 'C';
	pieces[2].place = 0;
//0
	pieces[3].t1.x = 0;
	pieces[3].t1.y = 0;
	pieces[3].t2.x = 1;
	pieces[3].t2.y = 0;
	pieces[3].t3.x = 1;
	pieces[3].t3.y = 1;
	pieces[3].t4.x = 2;
	pieces[3].t4.y = 1;
	pieces[3].id = 'D';
	pieces[3].place = 0;

	tab = ft_grid(4);
	if (estValide(pieces, tab, 0, 3, 0) == 42)
	{
		free(tab);
		tab = ft_grid(4);
		estValide(pieces, tab, 0, 4, 0);
	}
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 3)
		{
			ft_putchar(tab[x][y]);
			x++;
		}
		ft_putchar(tab[x][y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}*/
