/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:25:45 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/15 12:29:39 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('x');
	return (0);
}

int main ()
{
	void *mlx_ptr;
//	void *win_ptr;
	void *img;
//	int	pixel;
	
	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
	img = mlx_new_image(mlx_ptr, 1920, 1080);
//	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF);
//	pixel = mlx_string_put(mlx_ptr, win_ptr, 240, 240, 250, "A");
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_loop(mlx_ptr);
}