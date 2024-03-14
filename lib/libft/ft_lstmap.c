/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:43:31 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/18 14:28:26 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*root;
	void	*cl;

	if (!lst || !f)
		return (NULL);
	root = NULL;
	while (lst)
	{
		cl = f(lst->content);
		if (!cl)
			return (ft_lstclear(&root, del), NULL);
		new = ft_lstnew(cl);
		if (!new)
			return (ft_lstclear(&root, del), del(cl), NULL);
		ft_lstadd_back(&root, new);
		lst = lst->next;
	}
	return (root);
}
