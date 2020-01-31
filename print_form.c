/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:46 by smaccary          #+#    #+#             */
/*   Updated: 2020/01/31 07:12:10 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	print_form(const char *format, va_list *list)
{
	char	*str;
	int		count;
	t_infos infos;

	if (!(str = ft_substr(format, 0, get_conv((char *)format) + 1 - format)))
		return (write(1, "ERROR", 5));
	count = 0;
	infos = get_infos(str, list);
	printf("'%c' %d %d '%c'", infos.space, infos.width, infos.precision, infos.pos);
	free(str);
	return (count);
}
