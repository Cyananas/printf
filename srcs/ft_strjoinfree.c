/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:47:58 by pravry            #+#    #+#             */
/*   Updated: 2020/09/30 10:48:00 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_cat(char *dst, const char *src, int lens1, int lens2)
{
	int	i;

	i = 0;
	while (i < lens2)
	{
		dst[lens1 + i] = src[i];
		i++;
	}
	dst[lens1 + i] = '\0';
	return (dst);
}

char	*ft_cpy(char *dst, const char *src, int lens1)
{
	int	i;

	i = 0;
	while (i < lens1)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoinfree(char *s1, char *s2, int lens1, int lens2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((str = (char*)malloc(lens1 + lens2 + 1)) == NULL)
		return (NULL);
	ft_cpy(str, s1, lens1);
	ft_cat(str, s2, lens1, lens2);
	free(s1);
	free(s2);
	return (str);
}
