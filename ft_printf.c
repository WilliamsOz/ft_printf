/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:38:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/14 15:27:20 by wiozsert         ###   ########.fr       */
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
		arg_len = ft_strlen(data.arg_string);
	else if (data.conv == 'x' || data.conv == 'X' || data.conv == 'o')
		arg_len = ft_strlen(data.arg_string);
	else if (data.conv == 'u' || data.conv == 'd' || data.conv == 'i')
		arg_len = ft_strlen(data.arg_string);
	data.arg_len = arg_len;
	return (data);
}

t_data	exploit_data(t_data data)
{
	if (data.conv == 'c')
		data = treat_c(data);
	else if (data.conv == 's')
		treat_s(&data);
	else if (data.conv == 'p')
		data = treat_p(data);
	else if (data.conv == 'd' || data.conv == 'i')
		data = treat_d_i(data);
	else if (data.conv == 'x' || data.conv == 'X' || data.conv == 'o')
		data = treat_hex(data);
	else if (data.conv == 'u')
		data = treat_u_integer(data);
	return (data);
}

t_data	treat_content(const char *src, va_list list, t_data data)
{
	data = init_arg_and_data(data, 1);
	data = get_data(src, data, 0, list);
	data = get_arg(data, list);
	data = get_len_of_conv(data, 0);
	if (data.conv != 'n' && data.conv != '%')
		data = exploit_data(data);
	else if (data.conv == '%')
		data = treat_percent(data);
	return (data);
}

t_data	read_input(const char *src, va_list list, t_data data)
{
	int		keep;
	int		i;

	keep = 0;
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

	if (format[0] == '\0')
		return (0);
	if (check_all_errors(format) == -1)
		return (-1);
	data.len_c_str = 0;
	data.c_str = NULL;
	va_start(list, format);
	data = read_input(format, list, data);
	va_end(list);
	if (data.c_str == NULL)
		data.len_c_str = 0;
	else
	{
		write(1, data.c_str, data.len_c_str);
		free(data.c_str);
	}
	return (data.len_c_str);
}

int main(void)
{
	system("leaks cccns");
	ft_printf("[Salut Narvalo ,\n%s il est %d:%d]", "Ca va", 42, 42);
	return (0);
}