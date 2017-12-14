/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:08:17 by srossi            #+#    #+#             */
/*   Updated: 2017/12/14 16:58:20 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_sub_pt(int i, int j, t_tetri *piece)
{
	piece->t1.x = piece->t1.x - i ;
	piece->t2.x = piece->t2.x - i ;
	piece->t3.x = piece->t3.x - i ;
	piece->t4.x = piece->t4.x - i ;
	piece->t1.y = piece->t1.y - j ;
	piece->t2.y = piece->t2.y - j ;
	piece->t3.y = piece->t3.y - j ;
	piece->t4.y = piece->t4.y - j ;
	return ;
}

t_tetri	*ft_piece_reset(t_tetri *piece)
{
	int i;

	i = piece->t1.x;
	if (piece->t2.x < piece->t1.x)
		i = piece->t2.x;
	if (piece->t3.x < piece->t2.x)
		i = piece->t3.x;
	ft_sub_pt(i, (piece->t1.y), piece);
	ft_visual(piece);
	ft_putchar('\n');
/*	if (i != 0)
		ft_sub_pt(i, 0,  piece);*/
	return (piece);
}
