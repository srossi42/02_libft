/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:12:33 by srossi            #+#    #+#             */
/*   Updated: 2017/12/14 14:02:50 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUF_SIZE 21

void	ft_tetri_display(t_tetri *tetri)
{
	ft_putstr("Id vaut :");
	ft_putchar(tetri->id);
	ft_putchar('\n');
	ft_putstr("t1 a pour coordonnees (");
	ft_putnbr((tetri->t1).x);
	ft_putstr(", ");
	ft_putnbr((tetri->t1).y);
	ft_putstr(")\n");
	ft_putstr("t2 a pour coordonnees (");
	ft_putnbr((tetri->t2).x);
	ft_putstr(", ");
	ft_putnbr((tetri->t2).y);
	ft_putstr(")\n");
	ft_putstr("t3 a pour coordonnees (");
	ft_putnbr((tetri->t3).x);
	ft_putstr(", ");
	ft_putnbr((tetri->t3).y);
	ft_putstr(")\n");
	ft_putstr("t4 a pour coordonnees (");
	ft_putnbr((tetri->t4).x);
	ft_putstr(", ");
	ft_putnbr((tetri->t4).y);
	ft_putstr(")\n");
}

t_tetri *ft_tetrinew(char c, char *str)
{
	int i;
	int tab[8];
	t_tetri *tetri;
	i = 0;
	tetri = (t_tetri *)malloc(sizeof(*tetri));
	ft_extract_points(str, tab);
	tetri->id = c;
	tetri->t1.x = tab[i];
	(tetri->t1).y = tab[i + 1];
	(tetri->t2).x = tab[i + 2];
	(tetri->t2).y = tab[i + 3];
	(tetri->t3).x = tab[i + 4];
	(tetri->t3).y = tab[i + 5];
	(tetri->t4).x = tab[i + 6];
	(tetri->t4).y = tab[i + 7];
//	ft_tetri_display(tetri); // a suppr apres tests
	return (tetri);
}

void	ft_visual(t_tetri *piece) //a suppr apres tests
{
	char *str;
	int i;
	char tab[21];

	i = 0;
	str = "....\n....\n....\n....\n";
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	i = 0;
	while (tab[i] != '\0')
	{
		if ((piece->t1.x == i % 5 && piece->t1.y == i / 5) || (piece->t2.x == i % 5 && piece->t2.y == i / 5) ||
			(piece->t3.x == i % 5 && piece->t3.y == i / 5) || (piece->t4.x == i % 5 && piece->t4.y== i / 5))
			tab[i] = piece->id;
		i++;
	}
//		ft_putstr(tab);
}

int *ft_extract_points(char *str, int *tab)
{
	int i;
	int x;

	i = 0;
	x = 0;
//	ft_putstr(str);
//	ft_putchar('\n');
	while (str[i])
	{
		if (str[i] == '#')
		{
			tab[x] = i % 5;
			tab[x + 1] = i / 5;
			x = x + 2;
		}
		i++;
	}	
	return (tab);
}


t_list	*ft_read(char *argv, t_list *list)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	size_t	ret_check;
	char 	c;

	ret_check = 0;
	c = 'A';
	if ((fd = open(argv, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			ret_check = ret_check + ret;
			buf[ret] = '\0';
			if (!ft_valid_grid(buf))
				return (0);
			ft_lstaddtail(&list, (ft_lstnew((ft_piece_reset(ft_tetrinew(c, buf))), sizeof(t_tetri))));
			c++;
			ret++;
		}
		if (!(ret_check % 21 == 20))
			return (0);
	}
	else
		return (0);
	if (close(fd) == -1)
		return (0);
	return (list);
}
