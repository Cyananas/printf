/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:48:19 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 19:26:27 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_substr(char *s, int start, int len)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = (char *)malloc((sizeof(char)) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dst[i] = '\0';
		return (dst);
	}
	while (s[i + start] && len)
	{
		dst[i] = s[i + start];
		len--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
