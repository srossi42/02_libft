/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:53:00 by srossi            #+#    #+#             */
/*   Updated: 2017/11/18 19:17:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	test_memset(void)
{
	char str1[30] = "bonjour ceci est un test";
	char str2[30] = "bonjour ceci est un test";

	ft_putstr("---------- Test memset ----------\n");
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
	return (0);
}

int	test_bzero(void)
{
	char	str1[30] = "bonjour chaine 1";
	char	str2[30] = "deuxieme string de test";
	int		i;

	i = 0;
	ft_putstr("---------- Test bzero ----------\n");
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
	char s7[30] = "abcde";	
	char s8[30] = "abcde";	

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
	if (strchr(s7, 'f') == NULL && ft_strchr(s8, 'f') == NULL)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strrchr(void)
{
	char s1[30] = "abcdefghijklmnopqrdtuvwxyz";	
	char s2[30] = "abcdefghijklmnopqrdtuvwxyz";	
	char s3[30] = "";	
	char s4[30] = "";	
	char s5[30] = "abcde";	
	char s6[30] = "abcde";	
	char s7[30] = "abcde";	
	char s8[30] = "abcde";	
	char s9[30] = "Hello je tesx";	
	char s10[30] = "Hello je tesx";	

	ft_putstr("---------- Test strrchr ----------\n");

	if (ft_strcmp(strrchr(s1, 'd'),  ft_strrchr(s2, 'd')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strrchr(s3, '\0'),  ft_strrchr(s4, '\0')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp(strrchr(s5, '\0'),  ft_strrchr(s6, '\0')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (strrchr(s7, 'f') == NULL && ft_strrchr(s8, 'f') == NULL)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	if (strcmp(strrchr(s9, 'H'), ft_strrchr(s10, 'H')) == 0)
		ft_putstr("OK \n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strstr(void)
{
	char s1[30] = "aabzzzarzzzzztdcabcdefghijkxyz";	
	char s2[30] = "zzzztd";	
	char s3[30] = "";	
	char s4[30] = "";	
	char s5[30] = "aabzzzarzzzzztdcabcdefghijkx";	
	char s6[30] = "zziztd";	


	ft_putstr("---------- Test strstr ----------\n");

	if (ft_strcmp((strstr(s1, s2)),	ft_strstr(s1, s2)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp((strstr(s1, s3)),	ft_strstr(s1, s3)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (ft_strcmp((strstr(s3, s4)),	ft_strstr(s3, s4)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strstr(s5, s6) == ft_strstr(s5, s6))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strnstr(void)
{
	char s1[30] = "abcdefgablkhijklooo";	
	char s2[30] = "ablk";	
	char s3[30] = "abcdefgablkhijklooo";	
	char s4[30] = "ablk";	
	ft_putstr("---------- Test strnstr ----------\n");

	ft_putstr(strnstr(s1, s2, 11));
	ft_putchar('\n');
	ft_putstr(ft_strnstr(s3, s4, 11));
	ft_putchar('\n');
	if (ft_strcmp((strnstr(s1, s2, 10)), ft_strnstr(s3, s4, 10)) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strcmp(void)
{
	char s1[30] = "®abcdef";	
	char s2[30] = "®abcdef";	
	char s3[30] = "jklm";	
	char s4[30] = "nopq";	
	ft_putstr("---------- Test strcmp ----------\n");
	if (strcmp(s1, s2) - ft_strcmp(s1, s2) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strcmp(s3, s4) - ft_strcmp(s3, s4) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_strncmp(void)
{
	char s1[30] = "®abcdef";	
	char s2[30] = "®abc55def";	
	char s3[30] = "jklm";	
	char s4[30] = "nopq";	
	char s5[30] = "a";	
	char s6[30] = "q";	
	ft_putstr("---------- Test strncmp ----------\n");
	if (strncmp(s1, s2, 3) - ft_strncmp(s1, s2, 3) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strncmp(s1, s2, 6) - ft_strncmp(s1, s2, 6) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strncmp(s3, s4, 3) - ft_strncmp(s3, s4, 3) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (strncmp(s5, s6, 0) - ft_strncmp(s5, s6, 0) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_atoi(void)
{
	char s1[20] = "    -56";
	char s2[20] = "    +56";
	char s3[20] = "    +56";
	char s4[20] = " e  +56";
	char s5[20] = "    +56o";

	ft_putstr("---------- Test atoi ----------\n");
	if (atoi(s1) == ft_atoi(s1))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (atoi(s2) == ft_atoi(s2))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (atoi(s3) == ft_atoi(s3))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (atoi(s4) == ft_atoi(s4))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (atoi(s5) == ft_atoi(s5))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");

	return (0);
}

int	test_isalpha(void)
{
	int	c = 'e';
	int	c2 = 4;
	ft_putstr("---------- Test isalpha ----------\n");
	if (isalpha(c) != 0 && ft_isalpha(c) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isalpha(c2) == 0 && ft_isalpha(c2) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_isdigit(void)
{
	int	c = '0';
	int	c2 = 'e';
	ft_putstr("---------- Test isdigit ----------\n");
	if (isdigit(c) != 0 && ft_isdigit(c) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isdigit(c2) == 0 && ft_isdigit(c2) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_isalnum(void)
{
	int	c = '0';
	int	c2 = 'e';
	int	c3 = 'L';
	int	c4 = '@';
	ft_putstr("---------- Test isalnum ----------\n");
	if (isalnum(c) != 0 && ft_isalnum(c) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isalnum(c2) != 0 && ft_isalnum(c2) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isalnum(c3) != 0 && ft_isalnum(c3) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isalnum(c4) == 0 && ft_isalnum(c4) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_isascii(void)
{
	int	c = '0';
	int	c2 = 'e';
	int	c3 = 'L';
	int	c4 = 0xe1;	
	ft_putstr("---------- Test isascii ----------\n");
	if (isascii(c) != 0 && ft_isascii(c) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isascii(c2) != 0 && ft_isascii(c2) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isascii(c3) != 0 && ft_isascii(c3) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isascii(c4) == 0 && ft_isascii(c4) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_isprint(void)
{
	int	c1 = '0';
	int	c2 = 'e';
	int	c3 = 127;
	ft_putstr("---------- Test isprint ----------\n");
	if (isprint(c1) != 0 && ft_isprint(c1) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isprint(c2) != 0 && ft_isprint(c2) != 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (isprint(c3) == 0 && ft_isprint(c3) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_toupper(void)
{
	char c1 = 'a';
	char c2 = 'z';
	char c3 = '1';
	ft_putstr("---------- Test toupper ----------\n");
	if (toupper(c1) == ft_toupper(c1))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (toupper(c2) == ft_toupper(c2))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (toupper(c3) == ft_toupper(c3))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}

int	test_tolower(void)
{
	char c1 = 'A';
	char c2 = 'Z';
	char c3 = '1';
	ft_putstr("---------- Test tolower ----------\n");
	if (tolower(c1) == ft_tolower(c1))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (tolower(c2) == ft_tolower(c2))
		ft_putstr("OK\n");
	else
		ft_putstr("ERROR\n");
	if (tolower(c3) == ft_tolower(c3))
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
//	test_memcmp();
//	test_strlen();
//	test_strdup();
//	test_strcpy();
//	test_strncpy();
//	test_strcat();
//	test_strncat();
//	test_strlcat();
//	test_strchr();
//	test_strrchr();
//	test_strstr();
	//	test_strnstr();
//	test_strcmp();
	test_strncmp();
//	test_atoi();
//	test_isalpha();
//	test_isdigit();
//	test_isalnum();
//	test_isascii();
//	test_isprint();
//	test_toupper();
//	test_tolower();
	return (0);
}
