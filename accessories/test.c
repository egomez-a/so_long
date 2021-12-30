/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:42:07 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/29 12:44:08 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;

//first initialise the mlx
	mlx_ptr = mlx_init();

//create new window (mlx_ptr, x size, y size, and name of win)
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "Holiiii");

//create a square with pixels
	y = 250;
	while (y < 350)
	{
		x = 250;
		while (x < 350)
		{
			//this is the function to draw a pixel. it calls the ptr, win, x & y coordinates and 0RGB color (in this case red).)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0255000042);
			x++;
		}
		y++;
	}
	//mlx_loop function is in charge of the event log inside of the window
	mlx_loop(mlx_ptr);
	return (0);