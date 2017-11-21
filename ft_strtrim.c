/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:54:28 by srossi            #+#    #+#             */
/*   Updated: 2017/11/21 18:41:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int ft_def_start(char *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

int ft_def_end(char *s)
{
	int i;
	int end;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			end = i;
			i++;
		}
		i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s)
{
	int i;
	int start;
	int	end;
	char *s_cpy;

	i = 0;
	start = ft_def_start((char *)s);
	end = start;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			end = i;
			i++;
		}
		i++;
	}
	if(!(s_cpy = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s_cpy[i] = s[start];
		i++;
		start++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
