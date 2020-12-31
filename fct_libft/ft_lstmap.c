/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:27:25 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 17:59:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*data;

	if (f == NULL || lst == NULL)
		return (NULL);
	data = NULL;
	new_list = NULL;
	while (lst != NULL)
	{
		if ((data = f(lst->content)) == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if ((new_element = ft_lstnew(data)) == NULL)
		{
			del(data);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
