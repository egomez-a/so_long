/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:03:45 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/17 10:14:08 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main (void)
{
	int trgb;
	
	trgb = create_trgb(64, 98, 54 ,32);
	printf("%d\n", trgb);
	printf("%d\n", get_t(trgb));
	printf("%d\n", get_r(trgb));
	printf("%d\n", get_g(trgb));
	printf("%d\n", get_b(trgb));
}