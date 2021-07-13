/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:49:17 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:41:35 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_u_prec(t_format *form, char *res)
{
	int	i;

	i = ft_strlen(res) - 1;
	if (form->f_dot && form->pass == 0)
		while (++i < form->precision)
			res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
	else if (form->f_zero)
		while (++i < form->len)
			res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
	return (res);
}

static char	*ft_min_jus(t_format *form, char *res)
{
	int	i;

	i = ft_strlen(res) - 1;
	if (form->f_min)
		while (++i < form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), i, 1);
	else
		while ((++i < form->justify && form->f_zero == 0)
			|| (i < form->len && form->f_zero == 1))
			res = ft_strjoinfree(ft_strdup(" "), res, 1, i);
	return (res);
}

char		*ft_write_u(t_format *form, va_list *arg)
{
	unsigned int	tmp;
	char			*res;

	tmp = va_arg(*arg, unsigned int);
	if (tmp == 0 && form->f_dot && form->precision == 0 && form->pass == 0)
	{
		if ((res = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((res = ft_itoa_u(tmp)) == NULL)
		return (NULL);
	if (form->f_min && form->f_zero)
		form->f_zero = 0;
	if ((res = ft_u_prec(form, res)) == NULL)
		return (NULL);
	if ((res = ft_min_jus(form, res)) == NULL)
		return (NULL);
	form->size = form->size + ft_strlen(res);
	return (res);
}
