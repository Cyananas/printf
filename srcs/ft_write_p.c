/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:48:57 by pravry            #+#    #+#             */
/*   Updated: 2020/09/30 10:48:59 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_convert_addr(void *ptr)
{
	uintmax_t	src;
	char		*res;
	char		*hex;
	char		*conv;

	hex = "0123456789abcdef";
	src = (uintmax_t)ptr;
	if ((res = ft_strdup("0x")) == NULL)
		return (NULL);
	if ((conv = ft_strdup("")) == NULL)
		return (NULL);
	while (src > 0)
	{
		if ((conv = ft_conv_base(conv, hex[src % 16])) == NULL)
			return (NULL);
		src = src / 16;
	}
	return (ft_strjoinfree(res, conv, 2, ft_strlen(conv)));
}

char	*ft_conv_p(va_list *args)
{
	void	*tmp;
	char	*res;

	if ((tmp = va_arg(*args, void *)) == NULL)
	{
		if ((res = ft_strdup("0x0")) == NULL)
			return (NULL);
	}
	else if ((res = ft_convert_addr(tmp)) == NULL)
		return (NULL);
	return (res);
}

char	*ft_write_p(t_format *form, va_list *args)
{
	int		i;
	char	*res;

	if ((res = ft_conv_p(args)) == NULL)
		return (NULL);
	i = ft_strlen(res) - 1;
	if (form->f_min == 0)
		while (++i < form->justify)
			res = ft_strjoinfree(ft_strdup(" "), res, 1, i);
	else
		while (++i < form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), i, 1);
	form->size = form->size + ft_strlen(res);
	return (res);
}
