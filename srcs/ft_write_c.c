/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:48:28 by pravry            #+#    #+#             */
/*   Updated: 2020/09/30 10:48:30 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_write_c(t_format *form, va_list *arg)
{
	int		i;
	char	*res;

	i = 0;
	if ((res = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	res[0] = va_arg(*arg, int);
	res[1] = '\0';
	if (form->f_min)
		while (++i < form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), i, 1);
	else
		while (++i < form->justify)
			res = ft_strjoinfree(ft_strdup(" "), res, 1, i);
	if (form->justify != 0)
		form->size = form->size + form->justify;
	else
		form->size = form->size + 1;
	return (res);
}
