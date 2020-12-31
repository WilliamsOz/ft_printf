/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_or_hex_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:10:18 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/11 18:33:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data	get_address(t_data data, char *base, int i)
{
	char	res[19];
	
	if (data.arg_umax == 0)
	{
		data.arg_addr = "(nil)";
		return (data);
	}
	while (++i < 19)
		res[i] = '\0';
	i--;
	while (data.arg_umax > 0)
	{
		res[--i] = base[data.arg_umax % 16];
		data.arg_umax /= 16;
	}
	res[--i] = 'x';
	res[--i] = '0';
	data.arg_addr = ft_strsjoin(res + i, NULL, 0, 0);
	return (data);
}

int		get_lenforhex(unsigned long long ull, unsigned int ui)
{
	int		len;
	
	len = 0;
    if (ull == 0 && ui == 0)
        return (1);
	while (ull > 0)
	{
		len++;
		ull /= 16;	
	}
	while (ui > 0)
	{
		len++;
		ui /= 16;
	}
	return (len);
}

t_data	convert_tiny_base(t_data data, char *base_t, char *res)
{
	int i;

	i = get_lenforhex(data.arg_umax, 0) - 1;
	while (i >= 0)
	{
		res[i] = base_t[data.arg_umax % 16];
		i--;
		data.arg_umax /= 16;
	}
	data.hex_temp = ft_strsjoin(res, NULL, 0, 0);
	return (data);
}

t_data	convert_caps_base(t_data data, char *base_c, char *res)
{
	int i;

	i = get_lenforhex(data.arg_umax, 0) - 1;
	while (i >= 0)
	{
		res[i] = base_c[data.arg_umax % 16];
		i--;
		data.arg_umax /= 16;
	}
	data.hex_temp = ft_strsjoin(res, NULL, 0, 0);
	return (data);
}

t_data	convert_hex(t_data data, char *base_t, char *base_c, int indicator)
{
	char	res[17];
	int		i;

	i = -1;
	while (++i < 17)
		res[i] = '\0';	
	if (indicator == 0)
		data = convert_tiny_base(data, base_t, res);
	else if (indicator == 1)
		data = convert_caps_base(data, base_c, res);
	return (data);
}
