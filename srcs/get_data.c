/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:24:21 by user42            #+#    #+#             */
/*   Updated: 2021/01/08 11:34:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static int		get_indicator(const char *src, t_data *data, int i)
{
	while (src[i] == '-' || src[i] == '+' || src[i] == '0' || src[i] == ' ' ||
		src[i] == '#')
	{
		if (src[i] == '-')
			(*data).minus++;
		else if (src[i] == '+')
			(*data).plus++;
		else if (src[i] == '0')
			(*data).zero++;
		else if (src[i] == ' ')
			(*data).space++;
		else if (src[i] == '#')
			(*data).htag++;
		else if (src[i] == '.')
			(*data).precision_coma++;
		i++;
	}
	return (i);
}

static void		get_lenght(const char *src, t_data *data, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n')
	{
		if (src[i] == 'l' && src[i + 1] == 'l')
		{
			(*data).d_l++;
			while (src[i] == 'l')
				i++;
		}
		else if (src[i] == 'l')
			(*data).l++;
		else if (src[i] == 'h' && src[i + 1] == 'h')
		{
			(*data).d_h++;
			while (src[i] == 'h')
				i++;
		}
		else if (src[i] == 'h')
			(*data).h++;
		i++;
	}
}

static void		get_width(const char *src, t_data *data, int i)
{
	while ((src[i] >= '1' && src[i] <= '9') || src[i] == '*')
	{
		if ((src[i] >= '1' && src[i] <= '9') && (i == 0 || src[i - 1] == '-' ||
			src[i - 1] == '+' || src[i - 1] == ' ' || src[i - 1] == '#' ||
			src[i - 1] == '0'))
			(*data).width = ft_atoi(src + i);
		else if ((i == 0 || src[i - 1] == '-' || src[i - 1] == '+' ||
			src[i - 1] == '0' || src[i - 1] == ' ' || src[i - 1] == '#') &&
			(src[i] == '*'))
			(*data).width_star++;
		i++;
	}
}

static void		get_prcsion(const char *src, t_data *data, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n')
	{
		if (src[i] == '.')
			(*data).precision_coma++;
		else if (src[i] == '*' && src[i - 1] == '.')
			(*data).precision_star++;
		else if (src[i - 1] == '.' && src[i] >= '0' && src[i] <= '9')
			(*data).precision = ft_atoi(src + i);
		i++;
	}
}

t_data			get_data(const char *src, t_data data, int i, va_list list)
{
	i = get_indicator(src, &data, 0);
	get_width(src, &data, i);
	get_prcsion(src, &data, 0);
	get_lenght(src, &data, 0);
	if (data.width_star > 0)
	{
		data.width_star = va_arg(list, int);
		data.width = data.width_star;
	}
	if (data.precision_star > 0)
	{
		data.precision_star = va_arg(list, int);
		data.precision = data.precision_star;
	}
	data.conv = src[(get_end(src, 0) - 1)];
	return (data);
}
