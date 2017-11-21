/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:53:00 by srossi            #+#    #+#             */
/*   Updated: 2017/11/21 18:32:49 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

int	test_strtrim(void)
{
	ft_putstr(ft_strtrim(""));
	return(0);
}   

int	main(void)
{
	test_strtrim();
	return (0);
}
