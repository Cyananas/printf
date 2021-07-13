/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:47:06 by pravry            #+#    #+#             */
/*   Updated: 2020/10/01 17:20:27 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_len(unsigned int nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*ret;
	int		len;

	len = ft_len(n);
	if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (ret);
}
