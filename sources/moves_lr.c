/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_lr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:46:20 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:46:14 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tile_change_left(t_game *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	game->map.map2d[game->hero.y][game->hero.x] = 'P';
	game->map.map2d[game->hero.y][game->hero.x + 1] = '0';
	game->moves++;
	paint_game(game);
}

void	hero_left(t_game *game)
{
	if ((game->map.elems.collect == 0)
		&& (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y][game->hero.x + 1] = '0';
		game->moves++;
		paint_game(game);
		game->endgame = 42;
		printf("GAME OVER with %d moves!", game->moves);
	}
	else if ((game->map.map2d[game->hero.y][game->hero.x] == '1')
		|| (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
		game->hero.x += 1;
	else if (game->map.map2d[game->hero.y][game->hero.x] == '0')
		tile_change_left(game);
	else if (game->map.map2d[game->hero.y][game->hero.x] == 'C')
	{
		game->map.elems.collect--;
		tile_change_left(game);
	}
}

void	tile_change_right(t_game *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	game->map.map2d[game->hero.y][game->hero.x] = 'P';
	game->map.map2d[game->hero.y][game->hero.x - 1] = '0';
	game->moves++;
	paint_game(game);
}

void	hero_right(t_game *game)
{
	if ((game->map.elems.collect == 0)
		&& (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y][game->hero.x - 1] = '0';
		game->moves++;
		paint_game(game);
		game->endgame = 42;
		printf("GAME OVER with %d moves!", game->moves);
	}
	else if ((game->map.map2d[game->hero.y][game->hero.x] == '1')
		|| (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
		game->hero.x -= 1;
	else if (game->map.map2d[game->hero.y][game->hero.x] == '0')
		tile_change_right(game);
	else if (game->map.map2d[game->hero.y][game->hero.x] == 'C')
	{
		game->map.elems.collect--;
		tile_change_right(game);
	}
}
