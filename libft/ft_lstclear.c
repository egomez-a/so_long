/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:24:45 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/05 12:25:15 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pointer;
	t_list	*current;

	current = *lst;
	while (current)
	{
		pointer = current->next;
		(*del)(current->content);
		free(current);
		current = pointer;
	}
	(*lst) = NULL;
}
