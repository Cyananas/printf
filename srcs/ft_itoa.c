/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:46:57 by pravry            #+#    #+#             */
/*   Updated: 2020/09/30 10:46:58 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_len(int nbr)
{
	int len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*ret;
	int				sign;
	int				len;

	len = ft_len(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	nbr = (n < 0) ? -n : n;
	if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}
