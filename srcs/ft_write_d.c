/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:48:36 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:47:59 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_zero_prec(t_format *form, char *res)
{
	int	i;

	i = ft_strlen(res) - 1;
	if (form->f_zero && form->f_min == 0 && form->f_dot == 0 && form->len == 0)
		form->len = form->justify;
	while (++i < form->len)
	{
		res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
		if (res[1] == '-')
		{
			res[0] = '-';
			res[1] = '0';
		}
	}
	return (res);
}

char	*ft_d_prec(t_format *form, char *res)
{
	int	i;

	i = ft_strlen(res) - 1;
	if (form->f_dot && form->pass == 0)
	{
		if (res[0] == '-' && i + 1 <= form->precision)
			form->precision = form->precision + 1;
		while (++i < form->precision)
		{
			res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
			if (res[1] == '-')
			{
				res[0] = '-';
				res[1] = '0';
			}
		}
	}
	else if (form->f_zero)
		if ((res = ft_zero_prec(form, res)) == NULL)
			return (NULL);
	return (res);
}

char	*ft_min_jus(t_format *form, char *res)
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

char	*ft_write_d(t_format *form, va_list *arg)
{
	int		tmp;
	char	*res;

	tmp = va_arg(*arg, int);
	if (tmp == 0 && form->f_dot && form->precision == 0 && form->pass == 0)
	{
		if ((res = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((res = ft_itoa(tmp)) == NULL)
		return (NULL);
	if (form->f_min && form->f_zero)
	{
		form->f_zero = 0;
		if (form->justify == 0)
			form->justify = form->len;
	}
	if ((res = ft_d_prec(form, res)) == NULL)
		return (NULL);
	if ((res = ft_min_jus(form, res)) == NULL)
		return (NULL);
	form->size = form->size + ft_strlen(res);
	return (res);
}
