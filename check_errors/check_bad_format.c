/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bad_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:16:02 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 23:15:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		strcmp_missingconv(const char *src, char *conv, int i, int j)       	// Compare 2 string and return index + 1 if conversion is found, othewise return -1
{
	while (src[i] != '\0')
	{
		while (src[i] != '\0' && conv[j] != '\0' && src[i] != conv[j])
			j++;
		if (src[i] == conv[j] && conv[j] != '\0')
			return (i + 1);
		else
		{
			j = 0;
			i++;
		}
	}
	return (-1);
}

int		check_for_unknow(const char *src, int i, int keep)						// check that flag and conversion after % is know OK
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

int		check_format_after_lenght(const char *src, int start)
{
	while (src[start] == 'l' || src[start] == 'h')
		start++;
	if (src[start] != 'c' && src[start] != 's' && src[start] != 'p' && 
		src[start] != 'd' && src[start] != 'i' && src[start] != 'u' &&
		src[start] != 'x' && src[start] != 'X' && src[start] != '%')
		return (-1);
	return (1);
}

int		check_lenght(const char *src, int start, int end)
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

int		check_missing_conv(const char *src, char *conv, int i)					//check if conversion exist after %
{
	int start;

	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			i++;
			start = i;
			i = strcmp_missingconv(src, conv, i, 0);							// Compare 2 string and return index + 1 if conversion is found, othewise return -1
			if (i == -1)
				return (-1);
			else if (check_for_unknow(src, start, i - 1) == -1)
				return (-1);
			else if (check_compatibility(src, start, i - 1, 0) == -1)
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
