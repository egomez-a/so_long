/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:04:58 by egomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 11:17:18 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Esta función copia len bytes de src a dst. Las dos strings se pueden super-
** poner. La copia se hace de manera no destructiva.
** Añadimos el caso de que dst y src sean nulos pero len no.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if ((dst == 0) && (src == 0) && (len > 0))
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
