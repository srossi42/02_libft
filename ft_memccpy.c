/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:52:52 by srossi            #+#    #+#             */
/*   Updated: 2017/11/10 19:44:18 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
		size_t	i;
		char	*str;
		char	*src_cpy;

		i = 0;
		str = (char *)dst;
		src_cpy = (char *)src;
		while (i < n && (src_cpy[i] != (unsigned char)c))
			{
				str[i] = src_cpy[i];
				i++;
			}
		if (src_cpy[i] == c)
			return (&dst[i + 1]);
		return (NULL);
}
