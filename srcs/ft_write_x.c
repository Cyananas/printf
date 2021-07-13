/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:49:32 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:43:06 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t		i;
	char		*s1;
	char		*s2;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (i < n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	return (dst);
}

char	*ft_conv_base(char *str, char c)
{
	int		len;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if ((tmp = (char*)malloc(len + 2)) == NULL)
		return (NULL);
	ft_memcpy(tmp + 1, str, len);
	tmp[len + 1] = '\0';
	tmp[0] = c;
	free(str);
	return (tmp);
}

char	*ft_convert_x(unsigned int nb, t_format *form)
{
	char	*res;
	char	*base;

	if (form->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if ((res = ft_strdup("")) == NULL)
		return (NULL);
	if (nb == 0)
		if ((res = ft_conv_base(res, '0')) == NULL)
			return (NULL);
	while (nb > 0)
	{
		if ((res = ft_conv_base(res, base[nb % 16])) == NULL)
			return (NULL);
		nb = nb / 16;
	}
	return (res);
}

char	*ft_x_precision(unsigned int nb, t_format *form)
{
	int		i;
	char	*res;

	if (form->f_min && form->f_zero && form->pass == 0)
		form->f_zero = 0;
	if ((res = ft_convert_x(nb, form)) == NULL)
		return (NULL);
	i = ft_strlen(res) - 1;
	if (form->f_dot && form->pass == 0)
		while (++i < form->precision)
			res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
	if ((form->f_dot == 0 && form->f_zero)
		|| (form->f_zero && form->f_dot && form->pass == 1))
		while (++i < form->len)
			res = ft_strjoinfree(ft_strdup("0"), res, 1, i);
	return (res);
}

char	*ft_write_x(t_format *form, va_list *arg)
{
	char			*res;
	unsigned int	i;

	res = NULL;
	i = va_arg(*arg, unsigned int);
	if (i == 0 && form->f_dot && form->precision == 0 && form->pass == 0)
		if ((res = ft_strdup("")) == NULL)
			return (NULL);
	if (res == NULL && (res = ft_x_precision(i, form)) == NULL)
		return (NULL);
	i = ft_strlen(res) - 1;
	if (form->f_min)
		while (++i < (unsigned int)form->justify)
			res = ft_strjoinfree(res, ft_strdup(" "), i, 1);
	else
		while ((++i < (unsigned int)form->justify && form->f_zero == 0)
			|| (i < (unsigned int)form->len && form->f_zero == 1))
			res = ft_strjoinfree(ft_strdup(" "), res, 1, i);
	form->size = form->size + ft_strlen(res);
	return (res);
}
