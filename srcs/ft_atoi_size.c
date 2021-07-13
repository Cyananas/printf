/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:46:39 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:35:48 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check_sign(const char *str)
{
	int s;

	s = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	return (s);
}

int			ft_atoi_size(const char *str, int *size)
{
	int			i;
	int			sign;
	long		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = check_sign(str);
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			break ;
		else
		{
			res = (res * 10) + str[i] - 48;
			*size = *size + 1;
		}
		i++;
	}
	return (res * sign);
}
