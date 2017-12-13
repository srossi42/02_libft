/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:18:44 by srossi            #+#    #+#             */
/*   Updated: 2017/12/11 17:58:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#define BUF_SIZE 21

static	int	ft_isvalid_pt(int i, char *str) // verifie qu'un # donne est contigu avec au moins un autre # (voire plus)
{
		if ((i > 0 && str[i - 1] == '#') || (i < 18 && str[i + 1] == '#') ||
				(i < 14 && str[i + 5] == '#') || (i > 4 && str[i - 5] == '#'))
		return (1);
	return (0);
}

int	ft_valid_grid(char *str) //retourne 1 si grille OK (4 #, 4 \n en fin de ligne et 12 '.' )
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (k <= 4 && (str[i] == '.' || str[i] == '#' || str[i] == '\n'))
		{
			if (str[i] == '#')
			{
				if (ft_isvalid_pt(i, str))
					k++;
			}
			if (str[i] == '\n' && (i + 1) % 5 != 0 && (i + 1) % 21 != 0) // on verifie que si \n, il est bien en fin de ligne
				return (0);
		}
		i++;
	}
	if (k == 4 && (i == 20 || (i == 21 && str[20] == '\n')))
		return (1);
	else
		return (0);
}
