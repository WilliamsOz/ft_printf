/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:38:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 15:46:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

t_data	get_len_of_conv(t_data data, int arg_len)
{
	if (data.conv == 'c' || data.conv == '%')
	{
		data.arg_len = 1;
		return (data);
	}
	else if (data.conv == 's' || data.conv == 'p')
	{
		arg_len = ft_strlen(data.arg_string);
		// if (data.conv == 'p')
			// data->precision = (int)arg_len;
	}
	else if (data.conv == 'x' || data.conv == 'X')
		arg_len = ft_strlen(data.hex_temp);
	else if (data.conv == 'u' || data.conv == 'd' || data.conv == 'i')
		arg_len = ft_strlen(data.arg_string);
	data.arg_len = arg_len;
	return (data);
}

t_data	exploit_data(t_data data)
{
	if (data.conv == 'c' || data.conv == 's' || data.conv == 'p')
		data = treat_csp(data);






	
	// if (data.plus > 0 || data.arg_imax < 0)
	// 	b_size++;
	// else if (data.space > 0 && data.arg_imax > 0)
	// 	b_size++;
	// else if (data.arg_imax < 0 && (data.conv == 'd' || data.conv == 'i'))
	// 	b_size++;
	// if (data.conv == 'c' || data.conv == 's' || data.conv == 'p')
	// {
	// 	if (data.conv == 'c')
	// 		data.arg_string = put_char_in_str(data.arg_string, data.arg_char);
	// 	c_str = treat_cs(data, c_str, sign_of_width, b_size);
	// 	return (c_str);
	// }
	// if (data.conv == 'd' || data.conv == 'i' || data.conv == 'u')
	// {
	// 	c_str = treat_udi_di(data, c_str, sign_of_width, b_size);
	// 	return (c_str);
	// }
	// if (data.htag > 0)
	// 	b_size += 2;
	// if (data.conv == 'x' || data.conv == 'X')
	// 	c_str = treat_hex(data, c_str, sign_of_width, b_size);
	return (data);
}

t_data	treat_content(const char *src, va_list list, t_data data)
{
	size_t	buffer_size;
	int		sign_of_width;

	sign_of_width = 0;
	data = init_arg_and_data(data, 1);
	data = get_data(src, data, 0, list);
	data = get_arg(data, list);
	data = sort_data(data);
	data = get_len_of_conv(data, 0);
	// buffer_size = data.arg_len;
	// if (data.width > (int)buffer_size)
		// buffer_size = data.width;
	// if (data.precision > (int)buffer_size)
		// buffer_size = data.precision;
	if (data.conv != 'n' && data.conv != '%')
		data = exploit_data(data);
	// else if (data.conv == '%')
		// data.c_str = treat_percent(data, c_str, buffer_size, sign_of_width);
	return (data);
}

t_data	read_input(const char *src, va_list list, t_data data)
{
	int		keep;
	int		i;

	keep = 0;
	data.conv = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != '%')
		{
			while (src[i] != '%' && src[i] != '\0')
				i++;
			if (src[i] == '%' || src[i] == '\0')
				get_string(src, &data, keep, i);
		}
		else if (src[i] == '%')
		{
			data = treat_content(src + (i + 1), list, data);
			i = get_end(src, i + 1);
			keep = i;
		}
	}
	return (data);
}

int		ft_printf(const char *format, ...)
{
	t_data		data;
	va_list		list;
	int			displayed_char;

	if (format[0] == '\0')
		return (0);
	if (check_all_errors(format) == -1)
		return (-1);
	data.c_str = NULL;
	va_start(list, format);
	data = read_input(format, list, data);
	va_end(list);
	if (data.c_str != NULL)
		displayed_char = data.len_c_str;
	else
		displayed_char = 0;
	write(1, &data.c_str, data.len_c_str);
	return (displayed_char);
}
