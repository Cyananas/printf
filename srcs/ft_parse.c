/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:47:16 by pravry            #+#    #+#             */
/*   Updated: 2020/09/30 10:47:31 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_add(char *res, t_format *form, va_list *arg, int size)
{
	if (form->type == 'c')
		res = ft_strjoinfree(res, ft_write_c(form, arg), size, form->size);
	else if (form->type == 's')
		res = ft_strjoinfree(res, ft_write_s(form, arg), size, form->size);
	else if (form->type == 'd' || form->type == 'i')
		res = ft_strjoinfree(res, ft_write_d(form, arg), size, form->size);
	else if (form->type == 'u')
		res = ft_strjoinfree(res, ft_write_u(form, arg), size, form->size);
	else if (form->type == 'x' || form->type == 'X')
		res = ft_strjoinfree(res, ft_write_x(form, arg), size, form->size);
	else if (form->type == 'p')
		res = ft_strjoinfree(res, ft_write_p(form, arg), size, form->size);
	else
		res = ft_strjoinfree(res, ft_write_other(form, arg), size, form->size);
	return (res);
}

int		is_flag(char c, t_format *form)
{
	if (c != '-' && c != '0' && c != '.' && c != '*' &&
	!(c >= '0' && c <= '9'))
	{
		form->type = c;
		return (0);
	}
	return (1);
}

int		ft_parse_flag(char **format, t_format **form, va_list *args)
{
	int empty;

	empty = 0;
	*(format) = *(format) + 1;
	while (**format != '\0' && is_flag(**format, *form) == 1 && empty != 1)
	{
		if (**format == '-')
			*format = flag_min((*(format) + 1), *form, args);
		else if (**format == '.')
			*format = flag_dot((*(format) + 1), *form, args);
		else if (**format == '0')
			*format = flag_zero((*(format) + 1), *form, args);
		else if ((**format >= '0' && **format <= '9') || (*(*format) == '*'))
		{
			*format = flag_num(*(format), *form, args);
		}
		else
			empty = 1;
	}
	if (empty == 1)
		return (0);
	*(format) = *(format) + 1;
	return (1);
}

char	*ft_parse_format(va_list *arg, char *format, int *size, char *res)
{
	t_format	*form;

	form = NULL;
	while (*format)
	{
		form = ft_setup_form(form);
		if (*format == '%' && *(format + 1) != '\0')
		{
			if (ft_parse_flag(&format, &form, arg))
				res = ft_add(res, form, arg, *size);
		}
		else
		{
			res = ft_strjoinfree(res, ft_substr(format, 0, 1), *size, 1);
			format++;
			*size = *size + 1;
		}
		*size = *size + form->size;
		free(form);
	}
	return (res);
}
