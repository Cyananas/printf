/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:49:05 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 19:26:11 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_checkmin(t_format *form, char *res)
{
	int	i;

	i = ft_strlen(res) - 1;
	if (form->f_min)
		while (++i < form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), i, 1);
	else
		while (++i < form->justify)
			res = ft_strjoinfree(ft_strdup(" "), res, 1, i);
	return (res);
}

char	*ft_write_s(t_format *form, va_list *arg)
{
	char	*res;
	char	*tmp;

	if ((tmp = va_arg(*arg, char *)) == NULL)
		if ((tmp = ft_strdup("(null)")) == NULL)
			return (NULL);
	if (form->f_dot && form->pass == 0)
	{
		if ((res = ft_substr(tmp, 0, form->precision)) == NULL)
			return (NULL);
	}
	else if ((res = ft_substr(tmp, 0, ft_strlen(tmp))) == NULL)
		return (NULL);
	if (((res = ft_checkmin(form, res)) == NULL))
		return (NULL);
	form->size = form->size + ft_strlen(res);
	return (res);
}
