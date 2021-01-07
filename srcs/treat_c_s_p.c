/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c_s_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:51:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/07 15:49:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

// static char	*treat_positive_cs(t_data data, char *c_str, char *buffer, int i)
// {
// 	char	*temp;
// 	int		j;

// 	j = 0;
// 	if (data.width <= data.arg_len)
// 	{
// 		while (data.arg_len-- > 0 && data.precision-- > 0)
// 			buffer[i++] = data.arg_string[j++];
// 	}
// 	else if (data.width > data.arg_len)
// 	{
// 		while (data.width > data.arg_len && data.width-- > data.precision)
// 			buffer[i++] = ' ';
// 		while (j < data.precision)
// 			buffer[i++] = data.arg_string[j++];
// 	}
// 	temp = ft_strsjoin(c_str, buffer, 0, 0);
// 	if (c_str != NULL)
// 		free(c_str);
// 	c_str = temp;
// 	return (c_str);
// }

// static char	*treat_negative_cs(t_data data, char *c_str, char *buffer, int i)
// {
// 	char	*temp;
// 	int		j;

// 	j = 0;
// 	if (data.width <= data.arg_len)
// 	{
// 		while (data.arg_len-- > 0 && data.precision-- > 0)
// 			buffer[i++] = data.arg_string[j++];
// 	}
// 	else if (data.width > data.arg_len)
// 	{
// 		while (data.arg_len-- > 0 && data.precision-- > 0)
// 			buffer[i++] = data.arg_string[j++];
// 		while (i < data.width)
// 			buffer[i++] = ' ';
// 	}
// 	temp = ft_strsjoin(c_str, buffer, 0, 0);
// 	if (c_str != NULL)
// 		free(c_str);
// 	c_str = temp;
// 	return (c_str);
// }

t_data		sort_for_c_conv(t_data data, int *buffer_size)
{
	int size;

	size = 0;
	if (data.width > data.arg_len)
		size = data.width;
	else
		size = data.arg_len;
	if (data.plus > 0)
		data.plus = 0;
	if ((data.zero > 0 && data.minus > 0) || (data.zero > 0 && data.width < 0))
		data.zero = 0;
	if (data.width < 0)
	{
		data.sign_of_wdt = -1;
		data.width *= -1;
	}
	if (data.zero > 0)
		data.fill_width = '0';
	*buffer_size = *buffer_size + size;
	return (data);
}

char		*treat_pos_c()
{
	
}

char		*treat_neg_c()
{

}

t_data		treat_c(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		treat_pos_c();
	else if (data.sign_of_wdt == -1)
		treat_neg_c();
	data.c_str = join_string(data.c_str, buffer);
	return (data);
}

t_data		treat_csp(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.conv == 'c')
	{
		data = sort_for_c_conv(data, &buffer_size);
		data = treat_c(data, buffer_size);
	}
	// else if (data.conv == 's')
	// {
		// data = sort_for_s_conv();
		// c_str = treat_s();
	// }
	// else if (data.conv == 'p')
	// {
		// data = sort_for_p_conv();
		// c_str = treat_p();
	// }
	return (data);




	
	// char	buffer[b_size + 1];
	// buffer_memset(buffer, b_size + 1);
	// if (data.precision == -1 || data.precision > data.arg_len)
	// 	data.precision = data.arg_len;
	// if (data.precision >= data.arg_len && data.conv == 's' &&
	// 	data.null_str_indicator == 0)
	// 	data.precision = data.arg_len;
	// else if (data.arg_len > data.precision && data.conv == 's'
	// 	&& data.null_str_indicator == 0 && data.precision >= 0)
	// 	data.arg_len = data.precision;
	// if (data.conv == 'c')
	// 	data.precision = data.arg_len;
	// if (data.precision == -1 && data.null_str_indicator == 1)
	// 	data.precision = data.arg_len;
	// if (n_sign == 0)
	// 	c_str = treat_positive_cs(data, c_str, buffer, 0);
	// else if (n_sign > 0)
	// 	c_str = treat_negative_cs(data, c_str, buffer, 0);
	// return (c_str);
}
