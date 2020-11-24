/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compatibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:28:16 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 17:39:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		check_compatibility(const char *src, int start, int end, int is_width)	//check incompatibility
{
	if (src[start] == '0' && sp_zero(src, start, 0) == -1)
		return (-1);
	while (src[start] >= '0' && src[start] <= '9')
	{
		if (src[start] >= '1' && src[start] <= '9')
			is_width = 1;
		start++;
	}
	while (start < end)
	{
		if (src[start] == '+' && sp_plus(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == ' ' && sp_space(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == '-' && sp_minus(src, start, is_width) == -1)
			return (-1);
		else if (src[start] == '.' && pr_coma(src, start) == -1)
			return (-1);
		else if (src[start] == '*' && pr_star(src, start, 0) == -1)
			return (-1);
		start++;
	}
	return (1);
}