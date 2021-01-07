/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bad_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:16:02 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 11:40:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static int	isind_compatible(const char *src, int start, int end, int is_width)
{
	if (src[start] == '0' && sp_zero(src, start, 0) == -1)
		return (-1);
	while (src[start] >= '0' && src[start] <= '9')
	{
		if (src[start] >= '1' && src[start] <= '9')
			is_width = 1;
		start++;
	}
	while (start < end)
	{
		if (src[start] == '+' && sp_plus(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == ' ' && sp_space(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == '-' && sp_minus(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == '.' && pr_coma(src, start) == -1)
			return (-1);
		else if (src[start] == '*' && pr_star(src, start, 0) == -1)
			return (-1);
		start++;
	}
	return (1);
}

static int	check_for_unknow(const char *src, int i, int keep)
{
	while (i < keep)
	{
		if (src[i] != '-' && src[i] != '0' && src[i] != '.' && src[i] != '*' &&
			(!(src[i] >= '1' && src[i] <= '9')) && src[i] != '#' &&
			src[i] != ' ' && src[i] != '+' && src[i] != 'l' && src[i] != 'h')
			return (-1);
		else
			i++;
	}
	return (1);
}

static int	check_format_after_lenght(const char *src, int start)
{
	while (src[start] == 'l' || src[start] == 'h')
		start++;
	if (src[start] != 'c' && src[start] != 's' && src[start] != 'p' &&
		src[start] != 'd' && src[start] != 'i' && src[start] != 'u' &&
		src[start] != 'x' && src[start] != 'X' && src[start] != '%')
		return (-1);
	return (1);
}

static int	check_lenght(const char *src, int start, int end)
{
	t_data	data;

	data.l = 0;
	data.h = 0;
	while (start < end)
	{
		if ((src[start] == 'l' || src[start] == 'h') &&
			(check_format_after_lenght(src, start) == -1))
			return (-1);
		if (src[start] == 'l')
			data.l++;
		else if (src[start] == 'h')
			data.h++;
		start++;
	}
	if (data.l > 2 || data.h > 2)
		return (-1);
	else if (data.l > 0 && data.h > 0)
		return (-1);
	return (1);
}

int			check_missing_conv(const char *src, char *conv, int i)
{
	int start;

	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			i++;
			start = i;
			i = strcmp_missing_conv(src, conv, i, 0);
			if (i == -1)
				return (-1);
			else if (check_for_unknow(src, start, i - 1) == -1)
				return (-1);
			else if (isind_compatible(src, start, i - 1, 0) == -1)
				return (-1);
			else if (check_lenght(src, start, i - 1) == -1)
				return (-1);
			else if (check_format(src, start, i - 1) == -1)
				return (-1);
		}
		else
			i++;
	}
	return (1);
}
