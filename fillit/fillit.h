/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:07:49 by srossi            #+#    #+#             */
/*   Updated: 2017/12/14 17:34:45 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"

typedef struct		s_point
{
	int				x;
	int 			y;
}					t_point;

typedef struct		s_tetri
{
	char			id;
	t_point 		t1;
	t_point 		t2;
	t_point		 	t3;
	t_point 		t4;
}					t_tetri;

int		ft_valid(char *argv);
int		ft_valid_grid(char *str);
t_list	*ft_read(char *argv, t_list *list);
int		*ft_extract_points(char *str, int *tab);
t_tetri	*ft_tetrinew(char c, char *str);
void	ft_tetri_display(t_tetri *tetri); // a suppr ?
void	ft_printlist_tetri(t_list *list); // a supprimer 
//int		ft_valid_pts(t_point t1, t_point t2);
t_tetri	*ft_piece_reset(t_tetri *piece);
void	ft_visual(t_tetri *piece); // a suppr ?
char	**ft_grid(int size);
int		placable(t_tetri *piece, char **tab, int x, int y);
int		estValide(t_list *list, char **tab, int pos, int size, int nb_pieces);
void	ft_display(int size, char**tab);
#endif
