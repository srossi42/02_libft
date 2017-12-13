/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist_tetri.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:54:20 by srossi            #+#    #+#             */
/*   Updated: 2017/12/08 17:12:47 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_printlist_tetri(t_list *list)
{
	while (list)
	{

		ft_putstr("ID : ");
		ft_putchar(((t_tetri *)(list->content))->id);
		ft_putchar('\n');
		ft_putstr("t1 : ");
		ft_putchar('(' );
		ft_putnbr(((t_tetri *)(list->content))->t1.x);
		ft_putchar(',');
		ft_putnbr(((t_tetri *)(list->content))->t1.y);
		ft_putchar(')');
		ft_putchar('\n');
		ft_putstr("t2 : ");
		ft_putchar('(' );
		ft_putnbr(((t_tetri *)(list->content))->t2.x);
		ft_putchar(',');
		ft_putnbr(((t_tetri *)(list->content))->t2.y);
		ft_putchar(')');
		ft_putchar('\n');
		ft_putstr("t3 : ");
		ft_putchar('(' );
		ft_putnbr(((t_tetri *)(list->content))->t3.x);
		ft_putchar(',');
		ft_putnbr(((t_tetri *)(list->content))->t3.y);
		ft_putchar(')');
		ft_putchar('\n');
		ft_putstr("t4 : ");
		ft_putchar('(' );
		ft_putnbr(((t_tetri *)(list->content))->t4.x);
		ft_putchar(',');
		ft_putnbr(((t_tetri *)(list->content))->t4.y);
		ft_putchar(')');
		ft_putchar('\n');
		list = list->next;
	}
}
