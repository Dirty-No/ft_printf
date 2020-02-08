/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:17:52 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/08 01:05:04 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_space_str(char c, int size,
ssize_t (*my_write)(int, const void *, size_t))
{
	char	*str;
	int		count;

	str = malloc(sizeof(char) * size + 1);
	ft_memset(str, c, (size_t)size);
	str[size] = '\0';
	count = my_write(1, str, size);
	free(str);
	return (count);
}

/*
** infos.pos == 'r' if no '-' flag is used
*/

static int	print_right(t_infos infos, va_list *list)
{
	va_list	copy;
	int		count;

	va_copy(copy, *list);
	if (ft_strchr("di", infos.conv) && infos.space == '0' && get_curr_int(list) < 0)
		return (wp_ft_vprintf("-%0*d", infos.printer, infos.width -= 1, -1 * (int)va_arg(*list, int)));
	if ((infos.width - (count = print_conv(swp_printer(infos, no_write), &copy))) > 0)
		count += print_space_str(infos.space, infos.width - count, infos.printer);
	print_conv(infos, list);
	va_end(copy);
	return (count);
}

/*
static int	len_right(t_infos infos, va_list *list)
{
	va_list	copy;
	int		count;

	va_copy(copy, *list);
	count = print_conv(infos, list);
	va_end(copy);
	return ((count > infos.width) ? count : infos.width);
}
*/

int			print_space(t_infos infos, va_list *list)
{
	int	count;

	if (infos.pos == 'l' && (infos.width - (count = print_conv(infos, list))) > 0)
		count += print_space_str(' ', infos.width - count, infos.printer);
	else if (infos.pos == 'r')
		count = print_right(infos, list);
	return (count);
}

/*
int		len_space(t_infos infos, va_list *list)
{
	int		count;

	count = 0;
	if (infos.pos == 'l')
		count = len_flag(str + get_conv(str) - 1, list);
	else if (infos.pos == 'r')
		count = len_right(str, list, infos.width);
	return ((count > infos.width) ? count : infos.width);
}
	*/