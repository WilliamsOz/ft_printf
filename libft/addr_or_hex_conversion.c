/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_or_hex_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:10:18 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/25 15:02:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data			get_address(t_data data, char *base, int i)
{
	uintmax_t	temp;
	char		res[19];

	temp = data.arg_umax;
	if (temp == 0)
	{
		if (data.precision_coma > 0 && data.sign_of_prc != -1)
			data.arg_string = ft_strsjoin("0x", NULL, 0, 0);
		else
			data.arg_string = ft_strsjoin("0x0", NULL, 0, 0);
		return (data);
	}
	while (++i < 19)
		res[i] = '\0';
	i--;
	while (temp > 0)
	{
		res[--i] = base[temp % 16];
		temp /= 16;
	}
	res[--i] = 'x';
	res[--i] = '0';
	data.arg_string = ft_strsjoin(res + i, NULL, 0, 0);
	return (data);
}

static int		get_lenforhex(unsigned long long ull, unsigned int ui)
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

static t_data	convert_tiny_base(t_data data, char *base_t, char *res)
{
	uintmax_t	temp;
	int			i;

	temp = data.arg_umax;
	i = get_lenforhex(temp, 0) - 1;
	while (i >= 0)
	{
		res[i] = base_t[temp % 16];
		i--;
		temp /= 16;
	}
	data.arg_string = ft_strsjoin(res, NULL, 0, 0);
	return (data);
}

static t_data	convert_caps_base(t_data data, char *base_c, char *res)
{
	uintmax_t	temp;
	int			i;

	temp = data.arg_umax;
	i = get_lenforhex(temp, 0) - 1;
	while (i >= 0)
	{
		res[i] = base_c[temp % 16];
		i--;
		temp /= 16;
	}
	data.arg_string = ft_strsjoin(res, NULL, 0, 0);
	return (data);
}

t_data			convert_hex(t_data data, char *base_t, char *base_c, int ind)
{
	char	res[17];
	int		i;

	i = -1;
	while (++i < 17)
		res[i] = '\0';
	if (ind == 0)
		data = convert_tiny_base(data, base_t, res);
	else if (ind == 1)
		data = convert_caps_base(data, base_c, res);
	return (data);
}
