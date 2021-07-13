/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:48:44 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:36:58 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_char(char c)
{
	char	*tmp;

	if ((tmp = (char *)malloc(2)) == NULL)
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

static char	*ft_prec(t_format *form, char *res)
{
	int		i;

	i = 0;
	if (form->f_zero)
		while (++i < form->len)
			res = ft_strjoinfree(ft_strdup("0"), res, 1, ft_strlen(res));
	return (res);
}

char		*ft_write_other(t_format *form, va_list *arg)
{
	int		i;
	char	*res;

	(void)arg;
	if ((res = ft_char(form->type)) == NULL)
		return (NULL);
	if (form->f_min && form->f_zero)
		form->f_zero = 0;
	if ((res = ft_prec(form, res)) == NULL)
		return (NULL);
	i = 0;
	if (form->f_min)
		while (++i < form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), ft_strlen(res), 1);
	else
		while (++i < form->justify)
			res = ft_strjoinfree(ft_strdup(" "), res, 1, ft_strlen(res));
	form->size = form->size + ft_strlen(res);
	return (res);
}
