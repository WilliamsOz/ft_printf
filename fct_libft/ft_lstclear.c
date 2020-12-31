/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:40:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 15:21:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if ((*lst) != NULL && del != NULL)
	{
		while ((*lst) != NULL)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free((*lst));
			(*lst) = tmp;
		}
		(*lst) = NULL;
	}
}
