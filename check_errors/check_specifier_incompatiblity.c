/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier_incompatiblity.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:02:44 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 17:36:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		sp_minus(const char *src, int i, int is_width)							//check incompatibility for minus
{
	if (is_width == 1)
		return (-1);
	while (src[i] == '-')
		i++;
	while (src[i] >= '0' && src[i] <= '9')
	{
		if (src[i] >= '1' && src[i] <= '9')
			is_width = 1;
		i++;
	}
	if ((is_width == 1 && src[i] == '*') ||
		(is_width == 1 && src[i] == '+') ||
		(is_width == 1 && src[i] == ' ') ||
		(is_width == 1 && src[i] == '#') ||
		(is_width == 1 && src[i] == '-'))
		return (-1);
	return (1);
}

int		sp_plus(const char *src, int i, int is_width)				//check incompatibility for plus
{
	if (is_width == 1)
		return (-1);
	while (src[i] == '+')
		i++;
	while (src[i] >= '0' && src[i] <= '9')
	{
		if (src[i] >= '1' && src[i] <= '9')
			is_width = 1;
		i++;
	}
	if ((is_width == 1 && src[i] == '*') ||
		(is_width == 1 && src[i] == '+') ||
		(is_width == 1 && src[i] == ' ') ||
		(is_width == 1 && src[i] == '#') ||
		(is_width == 1 && src[i] == '-'))
		return (-1);
	return (1);
}

int		sp_space(const char *src, int i, int is_width)							//check incompatibility for space
{
	if (is_width == 1)
		return (-1);
	while (src[i] == ' ')
		i++;
	while (src[i] >= '0' && src[i] <= '9')
	{
		if (src[i] >= '1' && src[i] <= '9')
			is_width = 1;
		i++;
	}
	if ((is_width == 1 && src[i] == '-') ||
		(is_width == 1 && src[i] == '+') ||
		(is_width == 1 && src[i] == ' ') ||
		(is_width == 1 && src[i] == '#') ||
		(is_width == 1 && src[i] == '*'))
		return (-1);
	return (1);
}

int		sp_zero(const char *src, int i, int is_width)							//check incompatibility for zero
{
	while (src[i] == '0')
		i++;
	while (src[i] >= '0' && src[i] <= '9')
	{
		if (src[i] >= '1' && src[i] <= '9')
			is_width = 1;
		i++;
	}
	if ((is_width == 1 && src[i] == '-') ||
		(is_width == 1 && src[i] == '+') ||
		(is_width == 1 && src[i] == ' ') ||
		(is_width == 1 && src[i] == '#') ||
		(is_width == 1 && src[i] == '*'))
		return (-1);
	return (1);
}
