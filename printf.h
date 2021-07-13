/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:50:30 by pravry            #+#    #+#             */
/*   Updated: 2020/10/09 20:51:25 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>

typedef struct	s_format
{
	char	type;
	int		size;
	int		f_min;
	int		f_dot;
	int		f_zero;
	int		justify;
	int		precision;
	int		len;
	int		pass;

}				t_format;

int				ft_atoi(const char *str);
int				ft_atoi_size(const char *str, int *size);
int				ft_printf(const char *format, ...);
char			*ft_strjoinfree(char *s1, char *s2, int size, int index);
int				ft_strlen(char *str);
char			*ft_strdup(const char *str);
char			*ft_parse_format(va_list *arg, char *format,
				int *size, char *res);
char			*flag_min(char *format, t_format *formi, va_list *args);
char			*flag_zero(char *format, t_format *form, va_list *args);
char			*flag_num(char *format, t_format *form, va_list *args);
char			*flag_dot(char *format, t_format *form, va_list *args);
char			*ft_write_c(t_format *form, va_list *arg);
char			*ft_write_s(t_format *form, va_list *arg);
char			*ft_itoa(int n);
char			*ft_write_d(t_format *form, va_list *arg);
char			*ft_write_u(t_format *form, va_list *arg);
char			*ft_write_x(t_format *form, va_list *arg);
char			*ft_write_p(t_format *form, va_list *arg);
char			*ft_write_other(t_format *form, va_list *arg);
char			*ft_itoa_u(unsigned int n);
t_format		*ft_setup_form(t_format *form);
char			*ft_substr(char *format, int start, int len);
char			*ft_conv_base(char *conv, char c);

#endif
