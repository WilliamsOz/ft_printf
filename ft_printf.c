/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:38:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 09:55:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

size_t	get_len_of_conv(t_data *data, size_t arg_len, int *ptr_sign_of_width)
{
	if ((*data).width_star < 0 || (*data).minus > 0)
	{
		*ptr_sign_of_width = *ptr_sign_of_width + 1;
		if ((*data).width < 0)
			(*data).width *= -1;
	}
	if ((*data).conv == 'c' || (*data).conv == '%')
		return (1);
	else if ((*data).conv == 's' || (*data).conv == 'p')
	{
		arg_len = ft_strlen((*data).arg_string);
		if ((*data).conv == 'p')
			data->precision = (int)arg_len;
	}
	else if ((*data).conv == 'x' || (*data).conv == 'X')
		arg_len = ft_strlen((*data).hex_temp);
	else if ((*data).conv == 'u' || (*data).conv == 'd' || (*data).conv == 'i')
		arg_len = ft_strlen((*data).arg_string);
	return (arg_len);
}

char	*exploit_data(t_data data, char *c_str, int sign_of_width, int b_size)
{
	if (data.plus > 0 || data.arg_imax < 0)
		b_size++;
	else if (data.space > 0 && data.arg_imax > 0)
		b_size++;
	else if (data.arg_imax < 0 && (data.conv == 'd' || data.conv == 'i'))
		b_size++;
	if (data.conv == 'c' || data.conv == 's' || data.conv == 'p')
	{
		if (data.conv == 'c')
			data.arg_string = put_char_in_str(data.arg_string, data.arg_char);
		c_str = treat_cs(data, c_str, sign_of_width, b_size);
		return (c_str);
	}
	if (data.conv == 'd' || data.conv == 'i' || data.conv == 'u')
	{
		c_str = treat_udi_di(data, c_str, sign_of_width, b_size);
		return (c_str);
	}
	if (data.htag > 0)
		b_size += 2;
	if (data.conv == 'x' || data.conv == 'X')
		c_str = treat_hex(data, c_str, sign_of_width, b_size);
	return (c_str);
}

char	*treat_content(const char *src, va_list list, char *c_str)
{
	t_data	data;
	size_t	buffer_size;
	int		sign_of_width;

	data.conv = 0;
	sign_of_width = 0;
	data = init_arg_and_data(data, 1);
	data = get_data(src, data, 0, list);
	data = get_arg(data, list, c_str);
	data = sort_data(data);
	data.arg_len = get_len_of_conv(&data, 0, &sign_of_width);
	buffer_size = data.arg_len;
	if (data.width > (int)buffer_size)
		buffer_size = data.width;
	if (data.precision > (int)buffer_size)
		buffer_size = data.precision;
	if (data.conv == '%')
		c_str = treat_percent(data, c_str, buffer_size, sign_of_width);
	else if (data.conv != 'n' && data.conv != '%')
		c_str = exploit_data(data, c_str, sign_of_width, buffer_size);
	return (c_str);
}

char	*read_input(const char *src, va_list list, int i, char *c_str)
{
	int keep;

	keep = 0;
	while (src[i] != '\0')
	{
		if (src[i] != '%')
		{
			while (src[i] != '%' && src[i] != '\0')
				i++;
			if (src[i] == '%' || src[i] == '\0')
				c_str = get_string(src, c_str, keep, i);
			keep = i;
		}
		else if (src[i] == '%')
		{
			c_str = treat_content(src + (i + 1), list, c_str);
			i = get_end(src, i + 1);
			keep = i;
		}
	}
	return (c_str);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			displayed_char;
	char		*content_string;

	if (format[0] == '\0')
		return (0);
	if (check_all_errors(format) == -1)
		return (-1);
	content_string = NULL;
	va_start(list, format);
	content_string = read_input(format, list, 0, content_string);
	va_end(list);
	if (content_string != NULL)
		displayed_char = ft_strlen(content_string);
	else
		displayed_char = 0;
	ft_putstr(content_string);
	return (displayed_char);
}
