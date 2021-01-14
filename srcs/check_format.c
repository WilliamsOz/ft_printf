/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:50:45 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 11:40:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static int	check_bad_place(const char *src, int start, int end, t_data data)
{
	while (start < end)
	{
		while (src[start] == '-' || src[start] == '+' || src[start] == '0' ||
			src[start] == ' ' || src[start] == '#')
			start++;
		while (src[start] >= '1' && src[start] <= '9')
		{
			data.width++;
			start++;
		}
		if (data.width > 0 && ((src[start] == '-' || src[start] == '+' ||
			src[start] == ' ' || src[start] == '#' || src[start] == '*')))
			return (-1);
		while (src[start] == '*' || src[start] == '.')
		{
			start++;
			data.precision_coma++;
		}
		if (data.precision_coma > 0 && (src[start] == '-' ||
			src[start] == '+' || src[start] == ' ' || src[start] == '#'))
			return (-1);
		start++;
	}
	return (1);
}

static int	check_too_many(const char *src, int start, int end, t_data data)
{
	while (start < end)
	{
		if (src[start] == '*')
			data.precision_star++;
		else if (src[start] == '.')
			data.minus++;
		start++;
	}
	if (data.precision_star > 2 || data.minus > 1)
		return (-1);
	return (1);
}

int			check_format(const char *src, int start, int end)
{
	t_data	data;

	data.conv = 0;
	data = init_arg_and_data(data, 0);
	if (check_bad_place(src, start, end, data) == -1)
		return (-1);
	data = init_arg_and_data(data, 0);
	if (check_too_many(src, start, end, data) == -1)
		return (-1);
	return (1);
}
