/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:47:37 by pravry            #+#    #+#             */
/*   Updated: 2020/10/08 10:28:37 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_format	*ft_setup_form(t_format *form)
{
	if ((form = malloc(sizeof(t_format))) == NULL)
		return (NULL);
	form->type = '1';
	form->size = 0;
	form->f_min = 0;
	form->f_dot = 0;
	form->f_zero = 0;
	form->justify = 0;
	form->precision = 0;
	form->len = 0;
	form->pass = 0;
	return (form);
}
