/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:23:23 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:25:33 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_image(t_game *game, void *image, int x, int y)
{
	int		xx;
	int		yy;

	xx = x * 32;
	yy = y * 32;
	mlx_put_image_to_window(game->mlx, game->window.reference, image, xx, yy);
}

void	draw_hero(t_game *game, void *image, int x, int y)
{
	game->hero.x = x;
	game->hero.y = y;
	draw_image(game, image, x, y);
}

void	img_create(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image
		(game->mlx, "images/floor.xpm", &game->img.img_w, &game->img.img_h);
	game->img.wall = mlx_xpm_file_to_image
		(game->mlx, "images/wall.xpm", &game->img.img_w, &game->img.img_h);
	game->img.hero = mlx_xpm_file_to_image
		(game->mlx, "images/hero.xpm", &game->img.img_w, &game->img.img_h);
	game->img.collect = mlx_xpm_file_to_image
		(game->mlx, "images/collect.xpm", &game->img.img_w, &game->img.img_h);
	game->img.exit = mlx_xpm_file_to_image
		(game->mlx, "images/exit.xpm", &game->img.img_w, &game->img.img_h);
}
