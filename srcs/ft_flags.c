/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:46:49 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:39:09 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag_min(char *format, t_format *form, va_list *args)
{
	int	size;
	int	tmp;

	size = 0;
	tmp = 0;
	if (*format == '*')
		tmp = va_arg(*args, int);
	else if (*format == '-')
		size = 1;
	else
		tmp = ft_atoi_size(format, &size);
	if (tmp < 0)
		tmp = -tmp;
	if (form->justify == 0)
		form->justify = tmp;
	form->f_min = 1;
	if (*format == '*')
		return (format + 1);
	return (format + size);
}

char	*flag_dot(char *format, t_format *form, va_list *args)
{
	int	size;
	int	tmp;

	size = 0;
	tmp = 0;
	if (*format == '*')
		tmp = va_arg(*args, int);
	else if (*format == '.')
		size = 1;
	else
		tmp = ft_atoi_size(format, &size);
	if (tmp < 0)
		form->pass = 1;
	if (form->precision == 0 && tmp > 0)
		form->precision = tmp;
	form->f_dot = 1;
	if (*format == '*')
		return (format + 1);
	return (format + size);
}

char	*flag_zero(char *format, t_format *form, va_list *args)
{
	int		size;
	int		tmp;

	size = 0;
	tmp = 0;
	if (*format == '*')
		tmp = va_arg(*args, int);
	else
		tmp = ft_atoi_size(format, &size);
	if (tmp < 0)
	{
		tmp = -tmp;
		form->f_min = 1;
		if (form->justify == 0)
			form->justify = tmp;
	}
	if (form->len == 0)
		form->len = tmp;
	form->f_zero = 1;
	if (*format == '*')
		return (format + 1);
	return (format + size);
}

char	*flag_num(char *format, t_format *form, va_list *args)
{
	int size;
	int tmp;

	size = 0;
	tmp = 0;
	if (*format == '*')
		tmp = va_arg(*args, int);
	else
		tmp = ft_atoi_size(format, &size);
	if (tmp < 0)
	{
		tmp = -tmp;
		form->f_min = 1;
	}
	form->justify = tmp;
	if (*format == '*')
		return (format + 1);
	return (format + size);
}
