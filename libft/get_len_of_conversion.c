/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_of_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:49:45 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/25 15:05:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	get_len_of_conv(t_data data)
{
	if (data.conv == 'c' || data.conv == '%')
	{
		data.arg_len = 1;
		return (data);
	}
	else if (data.conv == 'p')
		data.arg_len = ft_strlen(data.arg_string);
	else if (data.conv == 's')
		data.arg_len = ft_strlen(data.arg_string);
	else if (data.conv == 'x' || data.conv == 'X' || data.conv == 'o')
		data.arg_len = ft_strlen(data.arg_string);
	else if (data.conv == 'u' || data.conv == 'd' || data.conv == 'i')
		data.arg_len = ft_strlen(data.arg_string);
	return (data);
}
