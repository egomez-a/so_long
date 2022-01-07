/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:19:07 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:23:01 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = new_window(game->mlx, game->map.cols * 32,
			game->map.lines * 32, "Bienvenido al juego de so_long!");
	game->moves = 0;
	img_create(game);
	paint_game(game);
}

int	paint_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map2d[y])
	{
		x = 0;
		while (game->map.map2d[y][x])
		{
			if (game->map.map2d[y][x] == '1')
				draw_image(game, game->img.wall, x, y);
			else if (game->map.map2d[y][x] == '0')
				draw_image(game, game->img.floor, x, y);
			else if (game->map.map2d[y][x] == 'P')
				draw_hero(game, game->img.hero, x, y);
			else if (game->map.map2d[y][x] == 'C')
				draw_image(game, game->img.collect, x, y);
			else if (game->map.map2d[y][x] == 'E')
				draw_image(game, game->img.exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

t_window	new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
