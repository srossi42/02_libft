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

int	test_memmove(void)
{
	char src[30] = "abcdefghijklmnopqrstuvwxyz";
	char dst[30] = "ceci est une chaine";
	char src2[30] = "abcdefghijklmnopqrstuvwxyz";
	char dst2[30] = "ceci est une chaine";
	char src3[30] = "abcdefghijklmnopqrstuvwxyz";
	char *dst3;
	char src4[30] = "abcdefghijklmnopqrstuvwxyz";
	char *dst4;
	char src5[30] = "abcdefghijklmnopqrstuvwxyz";
	char *dst5;
	char src6[30] = "abcdefghijklmnopqrstuvwxyz";
	char *dst6;

	dst3 = &src3[4];
	dst4 = &src4[4];
	dst5 = &src5[0];
	dst6 = &src6[0];

	ft_putstr("---------- Test memmove ----------\n");
	
	memmove(dst, src, 4);
	ft_memmove(dst2, src2, 4);
	memmove(dst3, src3, 7);
	ft_memmove(dst4, src4, 7);
	memmove(dst5, src5, 7);
	ft_memmove(dst6, src6, 7);
	if (ft_strcmp(dst, dst2) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(dst3, dst4) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(dst5, dst6) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_memchr(void)
{
	char s1[30] = "abcdefghijklmnopqrstuvwxyz";
	char s2[30] = "";

	ft_putstr("---------- Test memchr ----------\n");
	if (ft_strcmp(memchr(s1, 'z', 26), ft_memchr(s1, 'z', 26)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (memchr(s1, 'z', 25) == ft_memchr(s1, 'z', 25))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (memchr(s1, 'f', 4) == ft_memchr(s1, 'f', 4))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(memchr(s1, 'f', 7), ft_memchr(s1, 'f', 7)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (memchr(s2, 'f', 7) == ft_memchr(s2, 'f', 7))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_memcmp(void)
{
	char s1[30] = "abcdef";
	char s2[30] = "abxdef";
	char s3[30] = "";
	char s4[30] = "";

	ft_putstr("---------- Test memcmp ----------\n");
	if (memcmp(s1, s2, 2) == ft_memcmp(s1, s2, 2))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (memcmp(s1, s2, 4) == ft_memcmp(s1, s2, 4))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (memcmp(s3, s4, 0) == ft_memcmp(s3, s4, 0))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	main(void)
{
//	test_memset();
//	test_bzero();
//	test_memcpy();
//	test_memccpy();
//	test_memmove();
//	test_memchr();
	test_memcmp();
	return (0);
}
