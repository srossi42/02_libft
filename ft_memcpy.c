/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:52:20 by srossi            #+#    #+#             */
/*   Updated: 2017/11/10 17:56:25 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*str;
	char	*src_cpy;

	i = 0;
	str = (char *)dst;
	src_cpy = (char *)src;
	while (i < n)
	{
		str[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
