/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:10:23 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/03 19:33:15 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int get_width(char *format, va_list *list)
{
	return ((*format == '*') ? va_arg(*list, int) : ft_atoi(format));
}

static int	get_precision(char *format, va_list *list)
{
	return ((format = ft_strchr(format, '.')) ? get_width(format + 1, list) : 0);
}

static void check_infos(t_infos infos)
{
	if (infos.width < 0)
	{
		infos.width *= -1;
		infos.pos = 'l';
	}
	infos.pos = (infos.width < 0) ? 'l' : infos.pos;
	infos.space = ((infos.space == '0' && infos.precision) || infos.pos	== 'l'
		   	|| !ft_strchr(NUMERIC_TYPES, infos.conv)) ? ' ' : '0';
	return ;
}

t_infos		get_infos(char *format, va_list *list)
{
	t_infos	infos;
	if (*format)
		++format;
	if (*format == '-')
	{
		infos.pos = 'l';
		format++;
	}
	else
		infos.pos = 'r';
	if (*format == '0')
	{
		infos.space = (infos.pos == 'r') ? '0' : ' ';
		format++;
	}
	else
		infos.space = ' ';
	infos.width = get_width(format, list);
	infos.precision = get_precision(format, list);
	infos.conv = *get_conv(format);
	return (infos);
}
