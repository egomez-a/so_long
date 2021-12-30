/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:35:43 by egomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 11:16:13 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbpos;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbpos = n * (-1);
	}
	else
		nbpos = (unsigned int)n;
	if (nbpos >= 10)
	{
		ft_putnbr_fd(nbpos / 10, fd);
		ft_putnbr_fd(nbpos % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbpos, fd);
}
