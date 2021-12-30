/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:22:20 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/04 12:57:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		listlen;

	if (!lst)
		listlen = 0;
	else
	{
		listlen = 0;
		while (lst != NULL)
		{
			listlen++;
			lst = lst->next;
		}
	}
	return (listlen);
}
