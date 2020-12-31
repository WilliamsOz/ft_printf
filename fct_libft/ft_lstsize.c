/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:46:29 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 18:11:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		size;

	size = 0;
	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			size++;
		}
	}
	return (size);
}
