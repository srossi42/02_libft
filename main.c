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

int	test_strlen(void)
{
	char s1[30] = "";
	char s2[30] = "a";
	char s3[30] = "ab";
	char s4[30] = "abcde";
	char s5[30] = "abcdefgijklmnopqrstuvwxyz";

	ft_putstr("---------- Test strlen ----------\n");
	if (strlen(s1) == ft_strlen(s1))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strlen(s2) == ft_strlen(s2))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strlen(s3) == ft_strlen(s3))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strlen(s4) == ft_strlen(s4))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strlen(s5) == ft_strlen(s5))
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");

	return (0);
}

int	test_strdup(void)
{
	char s1[30] = "";
	char s2[30] = "abcdef";

	ft_putstr("---------- Test strdup ----------\n");
	if (ft_strcmp(strdup(s1), ft_strdup(s1)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strdup(s2), ft_strdup(s2)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strcpy(void)
{
	char src1[30] = "test abcde";
	char dst1[30] = "";
	char src2[30] = "test abcde";
	char dst2[30] = "";
	char src3[30] = "abcde";
	char dst3[30] = "xxxxxxx";
	char src4[30] = "abcde";
	char dst4[30] = "xxxxxx";

	ft_putstr("---------- Test strcpy ----------\n");
	if (ft_strcmp(strcpy(dst1, src1), ft_strcpy(dst2, src2)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strcpy(dst3, src3), ft_strcpy(dst4, src4)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strncpy(void)
{
	char src1[30] = "test abcde";
	char dst1[30] = "";
	char src2[30] = "test abcde";
	char dst2[30] = "";
	char src3[30] = "abcde";
	char dst3[30] = "xxxxxxx";
	char src4[30] = "abcde";
	char dst4[30] = "xxxxxxx";
	
	ft_putstr("---------- Test strncpy ----------\n");
	if (ft_strcmp(strncpy(dst1, src1, 2), ft_strncpy(dst2, src2, 2)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strncpy(dst3, src3, 5), ft_strncpy(dst4, src4, 5)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strcat(void)
{
	char s1[30] = "abcde";	
	char s2[30] = " fghij";	
	char s3[30] = "abcde";	
	char s4[30] = " fghij";	
	char s5[30] = "abcde";	
	char s6[30] = "";	
	char s7[30] = "abcde";	
	char s8[30] = "";	
	ft_putstr("---------- Test strcat ----------\n");
	if (ft_strcmp(strcat(s1, s2), ft_strcat(s3, s4)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strcat(s5, s6), ft_strcat(s7, s8)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strncat(void)
{
	char s1[30] = "abcde";	
	char s2[30] = " fghij";	
	char s3[30] = "abcde";	
	char s4[30] = " fghij";	
	char s5[30] = "abcde";	
	char s6[30] = "";	
	char s7[30] = "abcde";	
	char s8[30] = "";	
	ft_putstr("---------- Test strncat ----------\n");
	if (ft_strcmp(strncat(s1, s2, 8), ft_strncat(s3, s4, 8)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strncat(s5, s6, 2), ft_strncat(s7, s8, 2)) == 0)
			ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strlcat(void)
{
	char s1[20] = "abcdefghi";
	char s2[10] = "123";	
	char s3[20] = "abcdefghi";
	char s4[10] = "123";	
	char s5[10] = "ab";	
	char s6[10] = "";	
	char s7[10] = "ab";	
	char s8[10] = "";	
	char s9[20] = "abcde";	
	char s10[20] = "12345678";	
	char s11[20] = "abcde";	
	char s12[20] = "12345678";	
	char s13[20] = "abcde";	
	char s14[20] = "12345678";	
	char s15[20] = "abcde";	
	char s16[20] = "12345678";	
	ft_putstr("---------- Test strlcat ----------\n");
	if (strlcat(s1, s2, 14) == ft_strlcat(s3, s4, 14) && ft_strcmp(s1, s3) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (strlcat(s5, s6, 2) == ft_strlcat(s7, s8, 2) && ft_strcmp(s5, s7) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (strlcat(s9, s10, 7) == ft_strlcat(s11, s12, 7) && ft_strcmp(s9, s11) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (strlcat(s13, s14, 4) == ft_strlcat(s15, s16, 4) && ft_strcmp(s13, s15) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strchr(void)
{
	char s1[30] = "abcdefghijklmnopqrstuvwxyz";	
	char s2[30] = "abcdefghijklmnopqrstuvwxyz";	
	char s3[30] = "";	
	char s4[30] = "";	
	char s5[30] = "abcde";	
	char s6[30] = "abcde";	
	ft_putstr("---------- Test strchr ----------\n");
	if (ft_strcmp(strchr(s1, 'd'),  ft_strchr(s2, 'd')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strchr(s3, '\0'),  ft_strchr(s4, '\0')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strchr(s5, '\0'),  ft_strchr(s6, '\0')) == 0)
		ft_putstr("OK \n");
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
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strlcat();
	test_strchr();
	return (0);
}
