/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:53:00 by srossi            #+#    #+#             */
/*   Updated: 2017/11/10 19:55:38 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_memset(void)
{
	char str1[30] = "bonjour ceci est un test";
	char str2[30] = "bonjour ceci est un test";

	ft_putstr("---------- Test memset ----------\n");
	ft_putchar('\n');
	if (ft_strcmp(memset(str1, 'x', 5), ft_memset(str2, 'x', 5)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(memset(str1, 'a', 25), ft_memset(str2, 'a', 25)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(memset(str1, 0, 0), ft_memset(str2, 0, 0)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	ft_putchar('\n');
	return (0);
}

int	test_bzero(void)
{
	char	str1[30] = "bonjour chaine 1";
	char	str2[30] = "deuxieme string de test";
	int		i;

	i = 0;
	ft_putstr("---------- Test bzero ----------\n");
	ft_putchar('\n');
	bzero(str1, 0);
	ft_bzero(str2, 0);
	if (ft_strcmp(str1, str2) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	bzero(str1, 4);
	ft_bzero(str2, 4);
	while (i < 4)
	{
		if (str1[i] == str2[i])
			ft_putchar('.');
		i++;
	}
	if (i == 4 && (str1[i + 1] != str2[i + 1]))
		ft_putstr(" OK\n");
	else
		ft_putstr(" ERROR\n");
	return (0);
}

int	test_memcpy(void)
{
	char dst[30] = "ceci est une chaine";
	char src[30] = "abcdefghijklmnopqrstuvwxyz";
	char dst2[30] = "ceci est une chaine";
	char src2[30] = "abcdefghijklmnopqrstuvwxyz";
	char dst3[30] = "";
	char src3[30] = "";
	char dst4[30] = "";
	char src4[30] = "";

	ft_putstr("---------- Test memcpy ----------\n");
	ft_putchar('\n');
	if (ft_strcmp(memcpy(dst, src, 5), ft_memcpy(dst2, src2, 5)) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	if (ft_strcmp(memcpy(dst, src, 0), ft_memcpy(dst2, src2, 0)) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	if (ft_strcmp(memcpy(dst3, src3, 0), ft_memcpy(dst4, src4, 0)) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	if (ft_strcmp(memcpy(dst3, src3, 2), ft_memcpy(dst4, src4, 2)) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	return (0);
}

int	test_memccpy(void)
{
	char dst[30] = "ceci est une chaine";
	char src[30] = "abcdefghijklmnopqrstuvwxy";
	char dst2[30] = "ceci est une chaine";
	char src2[30] = "abcdefghijklmnopqrstuvwxy";
	char dst3[30] = "ceci est une chaine";
	char src3[30] = "abcdefghijklmnopqrstuvwxyz";
	char dst4[30] = "ceci est une chaine";
	char src4[30] = "abcdefghijklmnopqrstuvwxz";

	ft_putstr("---------- Test memccpy ----------\n");
	ft_putchar('\n');

	memccpy(dst, src, 91, 5);
	ft_memccpy(dst2, src2, 91, 5);
	if (ft_strcmp(dst, dst2) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	memccpy(dst3, src3, 91, 5);
	ft_memccpy(dst4, src4, 91, 5);
	if (ft_strcmp(dst3, dst4) == 0)
		ft_putstr("OK\n");
	else 
		ft_putstr("ERROR\n");
	return (0);
}

int	main(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	return (0);
}
