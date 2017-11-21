/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:45:28 by srossi            #+#    #+#             */
/*   Updated: 2017/11/21 16:02:45 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	f_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		l;

	i = f_strlen(s1);
	j = f_strlen(s2);
	k = 0;
	l = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (i + j + 1))))
		return (NULL);
	while (k < i && s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	while (k < (i + j) && s2[l] != '\0')
	{
		str[k] = s2[l];
		k++;
		l++;
	}
	str[k] = '\0';
	return (str);
}
