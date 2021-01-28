/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:24:21 by user42            #+#    #+#             */
/*   Updated: 2021/01/28 10:47:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	get_lenght(const char *src, t_data data, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n')
	{
		if (src[i] == 'l' && src[i + 1] == 'l')
		{
			data.d_l++;
			while (src[i] == 'l')
				i++;
		}
		else if (src[i] == 'l')
			data.l++;
		else if (src[i] == 'h' && src[i + 1] == 'h')
		{
			data.d_h++;
			while (src[i] == 'h')
				i++;
		}
		else if (src[i] == 'h')
			data.h++;
		i++;
	}
	return (data);
}

static t_data	get_prcsion(const char *src, t_data data, int i, va_list list)
{
	while (src[i] != '.' && src[i] != 'c' && src[i] != 's' && src[i] != 'p' &&
		src[i] != 'd' && src[i] != 'i' && src[i] != 'u' && src[i] != 'x' &&
		src[i] != 'X' && src[i] != '%' && src[i] != 'n')
		i++;
	if (src[i] == '.')
	{
		data.precision_coma++;
		i++;
	}
	if (src[i] == '*')
	{
		data.precision_star++;
		data.precision = va_arg(list, int);
		if (data.precision < 0)
		{
			data.sign_of_prc = -1;
			data.precision *= -1;
		}
	}
	else if (src[i] >= '0' && src[i] <= '9')
		data.precision = ft_atoi(src + i);
	return (data);
}

static t_data	get_width(const char *src, t_data data, int i, va_list list)
{
	while (src[i] == '-' || src[i] == '+' || src[i] == '0' || src[i] == ' ' ||
		src[i] == '#')
		i++;
	if (src[i] >= '1' && src[i] <= '9')
		data.width = ft_atoi(src + i);
	else if (src[i] == '*')
	{
		data.width_star++;
		data.width = va_arg(list, int);
	}
	if (data.width < 0 || data.minus > 0)
		data.sign_of_wdt = -1;
	if (data.width < 0)
		data.width *= -1;
	return (data);
}

static t_data	get_ind(const char *src, t_data data, int i, va_list list)
{
	while ((src[i] == '-' || src[i] == '+' || src[i] == ' ' ||
		src[i] == '#' || src[i] == '0'))
	{
		if (src[i] == '-')
			data.minus++;
		else if (src[i] == '+')
			data.plus++;
		else if (src[i] == '0')
			data.zero++;
		else if (src[i] == ' ')
			data.space++;
		else if (src[i] == '#')
			data.htag++;
		i++;
	}
	data = get_width(src, data, 0, list);
	data = get_prcsion(src, data, 0, list);
	data = get_lenght(src, data, 0);
	return (data);
}

t_data			get_data(const char *src, t_data data, va_list list)
{
	data = get_ind(src, data, 0, list);
	data.conv = src[(get_end(src, 0) - 1)];
	return (data);
}
