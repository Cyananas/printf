/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 08:30:38 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:47:43 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*res;
	int		out;
	int		size;

	out = 0;
	size = 0;
	if (format == NULL)
		return (out);
	if ((res = ft_strdup("")) == NULL)
		return (0);
	va_start(args, format);
	if ((res = ft_parse_format(&args, (char *)format, &size, res)) == NULL)
		return (0);
	write(1, res, size);
	out = size;
	free(res);
	va_end(args);
	return (out);
}
