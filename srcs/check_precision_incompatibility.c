/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_incompatibility.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:12:03 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 11:41:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		pr_coma(const char *src, int i)
{
	if (src[i + 1] == ' ' || src[i + 1] == '.')
		return (-1);
	i++;
	while (src[i] >= '0' && src[i] <= '9')
		i++;
	if (src[i] == '-' || src[i] == '+' || src[i] == ' ' || src[i] == '#' ||
		src[i] == '.')
		return (-1);
	return (1);
}

int		pr_star(const char *src, int i, int is_width)
{
	if (src[i - 1] >= '1' && src[i - 1] <= '9')
		is_width++;
	if (is_width == 1)
		return (-1);
	if ((src[i + 1] >= '0' && src[i + 1] <= '9') || (src[i + 1] == '*' ||
		src[i + 1] == '-' || src[i + 1] == ' ' || src[i + 1] == '#'))
		return (-1);
	return (1);
}
