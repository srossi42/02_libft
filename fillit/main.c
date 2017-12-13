/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:25:26 by jlemahie          #+#    #+#             */
/*   Updated: 2017/12/13 18:09:41 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

int		ft_sqrt(int nb) // racine carree arrondie au int superieur
{
	int x;

	x = 1;
	while (x * x < nb)
		x++;
	return (x);
}

char	**ft_grid(int size)  // Creer le carre rempli de points
{
	char	**tab;
	int		x;
	int		y;

	tab = malloc(sizeof(char*) * size + 1);
	y = 0;
	while (y < size)
	{
		tab[y] = malloc(sizeof(char) * size + 1);
		x = 0;
		while (x < size)
		{
			tab[y][x] = '.';
			x++;
		}
		tab[y][x] = '\n';
		y++;
	}
	return (tab);
}

int		ft_fil(t_tetri pieces, char **tab)
{

}

char	**ft_blablou(int nbrPieces, t_tetri pieces) // Appelle la fonction grid, rempli le tableau, si reussis pas augmente la taille et reessaye
{
	int		size;
	char	**tab;

	size = ft_sqrt(nbrPieces * 4);
	tab = ft_grid(size);
	while ((tab = ft_fil(pieces, tab)) == 0)  // fonction fil qui remplit le tableau (pas faite)
	{
		free(tab);
		size++;
		tab = ft_grid(size);
	}
	return (tab);  // retourne le tableau final a afficher
}
