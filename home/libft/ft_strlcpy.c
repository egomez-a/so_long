/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:06:23 by egomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 11:11:42 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcpy() takes the full size of the destination buffer and guarantees
** NUL-termination if there is room.  Room for the NUL should be included in
** dstsize. Returns size of src, the string it tried to create.
** strlcpy() copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	lensrc;

	if (!src || !dest)
		return (0);
	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	j = 0;
	if (size > 0)
	{
		while (src[j] != '\0' && j < size - 1)
		{
			dest[j] = src[j];
			j++;
		}
		if (j < size)
			dest[j] = '\0';
	}
	return (lensrc);
}
