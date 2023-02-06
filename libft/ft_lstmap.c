/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:31 by mi                #+#    #+#             */
/*   Updated: 2022/11/27 14:34:53 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_clear(void (*del)(void *), char *str, t_list *head)
{
	del(str);
	ft_lstclear(&head, del);
	return (NULL);
}

static void	*ft_free_del(void (*del)(void *), char *str)
{
	del(str);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*head;
	t_list	*current;
	char	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	current = lst;
	tmp = f(current->content);
	new_node = ft_lstnew(tmp);
	if (new_node == NULL)
		return (ft_free_del(del, tmp));
	head = new_node;
	current = current->next;
	while (current)
	{
		tmp = f(current->content);
		new_node = ft_lstnew(tmp);
		if (new_node == NULL)
			return (ft_free_clear(del, tmp, head));
		ft_lstadd_back(&head, new_node);
		current = current->next;
	}
	return (head);
}
