/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:38:57 by jlemahie          #+#    #+#             */
/*   Updated: 2017/12/14 18:58:58 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

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

int	placable(t_tetri *piece, char **tab, int x, int y)
{
		ft_putstr("x vaut : ");
		ft_putnbr(x);
		ft_putchar('\n');
		ft_putstr("y vaut : ");
		ft_putnbr(y);
		ft_putchar('\n');
	/*	ft_putstr("x1 vaut : ");
		ft_putnbr(piece->t1.x);
		ft_putchar('\n');
		ft_putstr("y1 vaut : ");
		ft_putnbr(piece->t1.y);
		ft_putchar('\n');
		ft_putstr("x2 vaut : ");
		ft_putnbr(piece->t2.x);
		ft_putchar('\n');
		ft_putstr("y2 vaut : ");
		ft_putnbr(piece->t1.y);
		ft_putchar('\n');
		ft_putstr("x3 vaut : ");
		ft_putnbr(piece->t3.x);
		ft_putchar('\n');
		ft_putstr("y1 vaut : ");
		ft_putnbr(piece->t3.y);
		ft_putchar('\n');
		ft_putstr("x4 vaut : ");
		ft_putnbr(piece->t4.x);
		ft_putchar('\n');
		ft_putstr("y4 vaut : ");
		ft_putnbr(piece->t4.y);
		ft_putchar('\n');*/
		if (tab[x + piece->t1.x][y + piece->t1.y] == '.' &&
				tab[x + piece->t2.x][y + piece->t2.y] == '.' &&
				tab[x + piece->t3.x][y + piece->t3.y] == '.' &&
				tab[x + piece->t4.x][y + piece->t4.y] == '.')
		{
			return (1);
		}
		return (0);
}

int estValide (t_list *list, char **tab, int pos, int size, int nb_pieces)
{
	int	x;
	int	y;
	int pieces_ok;

	pieces_ok = 0;
	if (pos == size*size)
	{
		ft_putendl("POS == SIZE*SIZE");
//		if (piece[0].place == 1 && piece[1].place == 1 && piece[2].place == 1 && piece[3].place == 1)
			return (1);
//		else
//		{
//			return (0);
//		}
	}
	x = pos/size;
	y = pos%size;
	ft_putendl("On rentre dans un nouveau ta mere");
	ft_putstr("X ");
	ft_putnbr(x);
	write(1, "\nY ", 3);
	ft_putnbr(y);
	write(1, "\n", 1);
	if (tab[x][y] != '.')
	{
		ft_putstr("pouet \n");
		return (estValide(list, tab, pos + 1, size, nb_pieces));
	}
	while (pos < size*size && pieces_ok <= nb_pieces)
	{
		y = pos/size;
		x = pos%size;
	//	ft_putendl("BOUCLE WHILE");			
		ft_display(size, tab);
		ft_putchar('\n');
		if (!list || pieces_ok == nb_pieces)
			return (1);
		if (placable(((t_tetri *)(list->content)), tab, x, y))
		{
			ft_putendl("placable !!");
			tab[x + ((t_tetri *)(list->content))->t1.x][y + ((t_tetri *)(list->content))->t1.y] = ((t_tetri *)list->content)->id;
			tab[x + ((t_tetri *)(list->content))->t2.x][y + ((t_tetri *)(list->content))->t2.y] = ((t_tetri *)list->content)->id;
			tab[x + ((t_tetri *)(list->content))->t3.x][y + ((t_tetri *)(list->content))->t3.y] = ((t_tetri *)list->content)->id;
			tab[x + ((t_tetri *)(list->content))->t4.x][y + ((t_tetri *)(list->content))->t4.y] = ((t_tetri *)list->content)->id;
			ft_display(size, tab);
			pieces_ok++;
			if (pieces_ok == nb_pieces)
				return (1);
			if ((estValide (list = list->next, tab, 0, size, nb_pieces)) == 1)
				return (1);
			else
			{
				ft_putendl("pas placable !!");
				tab[x + (((t_tetri *)list->content))->t1.x][y + (((t_tetri *)list->content))->t1.y] = '.';
				tab[x + (((t_tetri *)list->content))->t2.x][y + (((t_tetri *)list->content))->t2.y] = '.';
				tab[x + (((t_tetri *)list->content))->t3.x][y + (((t_tetri *)list->content))->t3.y] = '.';
				tab[x + (((t_tetri *)list->content))->t4.x][y + (((t_tetri *)list->content))->t4.y] = '.';
				//CHECK A FAIRE ICI AVEC IMPRESSION des X et Y et des t.x / t.y
				ft_putstr("x vaut : ");
				ft_putnbr(x);
				ft_putchar('\n');
				ft_putstr("y vaut : ");
				ft_putnbr(y);
				ft_putchar('\n');
				ft_putstr("x1 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t1.x);
				ft_putchar('\n');
				ft_putstr("y1 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t1.y);
				ft_putchar('\n');
				ft_putstr("x2 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t2.x);
				ft_putchar('\n');
				ft_putstr("y2 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t2.y);
				ft_putchar('\n');
				ft_putstr("x3 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t3.x);
				ft_putchar('\n');
				ft_putstr("y1 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t3.y);
				ft_putchar('\n');
				ft_putstr("x4 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t4.x);
				ft_putchar('\n');
				ft_putstr("y4 vaut : ");
				ft_putnbr((((t_tetri *)list->content))->t4.y);
				ft_putchar('\n');
				pieces_ok--;
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
